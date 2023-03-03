
#include <iostream>
#include <cstdlib>
#include <cstring>

using LARGE_INTEGER = uint64_t;

LARGE_INTEGER getTimeStamp(void)
{
    return __builtin_ia32_rdtsc();
}

unsigned int getElapsedMicroseconds(LARGE_INTEGER start)
{
    LARGE_INTEGER end = getTimeStamp();
    LARGE_INTEGER freq = 3300;

    double t = (double)(end - start) * 1000000.0 / (double)freq;
    return (unsigned int)(t + 0.5);
}

int main(int argc, char **argv)
{
    static const size_t singleBuffSize = 36ULL * 1024 * 1024;
    static const size_t nrOfBuffers = 6;

    volatile unsigned char *srcBuff = new unsigned char[singleBuffSize];
    volatile unsigned char *dstBuff = new unsigned char[singleBuffSize * nrOfBuffers];

    for (size_t j = 0; j < singleBuffSize; ++j)
    {
        srcBuff[j] = j;
    }

    for (int i = 0; i < (nrOfBuffers * 3); i++)
    {
        size_t buffIdx = (i % nrOfBuffers) * singleBuffSize;

        LARGE_INTEGER start = getTimeStamp();
        std::memcpy((void *)&dstBuff[buffIdx], (void *)srcBuff, singleBuffSize);
        unsigned int elapsedMicroseconds = getElapsedMicroseconds(start);

        printf("Loop %2d: buffer nr %2lu, elapsed time = %6u microseconds\n", i + 1, ((i % nrOfBuffers) + 1), elapsedMicroseconds);
    }

    size_t sum = 0;
    for (size_t j = 0; j < singleBuffSize * nrOfBuffers; ++j)
    {
        sum += dstBuff[j];
    }
    std::cout << "Sum:" << sum << std::endl;

    delete[] srcBuff;
    delete[] dstBuff;

    return 0;
}