#include <iostream>
#include <atomic>
#include <thread>
#include <unistd.h>
#include <boost/atomic.hpp>
#include <mutex>
#include <vector>
#include <benchmark/benchmark.h>
#include "boost/smart_ptr/detail/spinlock.hpp"
#include <linux/perf_event.h>
#include <xmmintrin.h>
#include <boost/thread.hpp>

static inline void yield(uint64_t k) {
    if (k < 4) {
    }

    else if (k < 16) {
        __asm__ __volatile__("rep; nop" : : : "memory");
    }

    else if (k < 32 || k & 1) {
        sched_yield();
    } else {
        struct timespec rqtp = {0, 0};

        rqtp.tv_sec = 0;
        rqtp.tv_nsec = 1000;

        nanosleep(&rqtp, 0);
    }
}

struct BadSpinLock {
    std::atomic<bool> lock_ = {false};

    void lock() {
        while (lock_.exchange(true))
            ;
    }

    void unlock() {
        lock_.store(false);
    }
};

struct NaiveSpinLock {
    NaiveSpinLock() {
        val = 0;
    }

    inline bool try_lock() {
        return __sync_lock_test_and_set(&val, 1) == 0;
    }

    inline void lock() {
        while (!try_lock())
            ;
    }
    inline void unlock() {
        __sync_synchronize();
        __sync_lock_release(&val);
    }

    volatile uint32_t val __attribute__((aligned(16)));
};

struct NaiveWithBackoff {
    inline bool try_lock() {
        return __sync_lock_test_and_set(&val, 1) == 0;
    }

    inline void lock() {
        for (unsigned k = 0; !try_lock(); ++k) {
            yield(k);
        }
    }
    inline void unlock() {
        __sync_synchronize();
        __sync_lock_release(&val);
    }

    volatile uint32_t val __attribute__((aligned(16))) = 0;
};

struct ErikSpinLock {
    std::atomic<bool> lock_ = {false};
    void lock() {
        for (;;) {
            if (!lock_.exchange(true, std::memory_order_acquire)) {
                break;
            }
            while (lock_.load(std::memory_order_relaxed)) {
                __builtin_ia32_pause();
            }
        }
    }
    void unlock() {
        lock_.store(false, std::memory_order_release);
    }
};

/*** WEIRD ***/

struct AtomicSpinLock {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

    void lock() {
        while (flag.test_and_set(std::memory_order_acquire))
            ;
    }
    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

struct AtomicWithBackoff {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;

    void lock() {
        for (uint64_t k = 0; flag.test_and_set(std::memory_order_acquire); ++k) {
            yield(k);
        }
    }
    void unlock() {
        flag.clear(std::memory_order_release);
    }
};

uint64_t counter = 0;

template <typename LockType>
static uint64_t increment() {
    uint64_t value = 0;
    static LockType my_lock;
    my_lock.lock();
    value = counter++;
    my_lock.unlock();
    return value;
}

template <typename LockType>
static void entry(int* flag) {
    uint64_t oldvalue = 0;
    while (*flag) {
        uint64_t newvalue = increment<LockType>();
        if (newvalue <= oldvalue) {
            std::cerr << "Error: value " << newvalue << " is less than " << oldvalue
                      << std::endl;
        }
        oldvalue = newvalue;
    }
}

#include <pthread.h>
static int getNumberOfAvailableCores() {
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    int result = pthread_getaffinity_np(pthread_self(), sizeof(cpuset), &cpuset);
    int counter = 0;
    for (int j = 0; j < CPU_SETSIZE; j++) {
        if (CPU_ISSET(j, &cpuset)) counter++;
    }
    return counter;
}

static int numcores =
    getNumberOfAvailableCores() - 1;  // boost::thread::physical_concurrency();

template <typename LockType>
static void testLock(benchmark::State& state) {
    int numthreads = state.range(0);
    if (numthreads > numcores) {
        numcores = numthreads;
    }

    std::vector<int> flags(numthreads, 1);
    std::vector<std::thread> threads;
    for (int j = 0; j < numthreads; ++j) {
        threads.emplace_back(entry<LockType>, &flags[j]);
    }

    for (auto _ : state) {
        increment<LockType>();
    }

    for (int j = 0; j < numthreads; ++j) {
        flags[j] = 0;
        threads[j].join();
    }
}

BENCHMARK(testLock<BadSpinLock>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<ErikSpinLock>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<NaiveSpinLock>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<NaiveWithBackoff>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<AtomicSpinLock>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<AtomicWithBackoff>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<std::mutex>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK(testLock<boost::detail::spinlock>)->RangeMultiplier(2)->Range(1, numcores);
BENCHMARK_MAIN();
