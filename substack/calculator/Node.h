#pragma once

#include "Pointer.h"

namespace Interpreter {

struct Node;

struct Visitor : public RefCounted {
    virtual void visit(Node*) = 0;
};

struct Node : public RefCounted {
    using RefCounted::RefCounted;
    virtual ~Node() {
    }
    virtual double calc() = 0;
    virtual void visit(Visitor& visitor) {
        visitor.visit(this);
    }
};

}  // namespace Interpreter