#pragma once

#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>

namespace Interpreter {

//--------------------------------------------------
// Pointers
//--------------------------------------------------
template <typename T>
using IntrusivePointer = boost::intrusive_ptr<T>;

//! Your basic intrusive pointer plus hashmap ability
template <typename T>
class Pointer : public IntrusivePointer<T> {
public:
    using IntrusivePointer<T>::IntrusivePointer;
    template <typename U>
    Pointer<U> as() const {
        U* ptr = dynamic_cast<U*>(this->get());
        if (ptr != nullptr) return Pointer<U>(ptr);
        return Pointer<U>();
    }

    //! Allows intrusive pointers to be used in hashmaps and hashsets
    bool operator==(const Pointer<T>& rhs) {
        return this->get() == rhs.get();
    }
};

// Base class for intrusive pointers
// Handles the counter and deleting of objects
struct RefCounted {
    RefCounted() {
        _counter = 0;
    }
    virtual ~RefCounted() {
    }
    RefCounted(const RefCounted&) = delete;
    RefCounted(RefCounted&&) = delete;
    friend inline void intrusive_ptr_add_ref(RefCounted* p) {
        p->_counter += 1;
    }

    friend inline void intrusive_ptr_release(RefCounted* p) {
        if (p->_counter > 1) {
            p->_counter--;
            return;
        }
        delete p;
    }
    int _counter = 0;
};

}  // namespace Interpreter
