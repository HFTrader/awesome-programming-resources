#pragma once

#include "Pointer.h"
#include "Node.h"
#include "FunctionOps.h"
#include <string_view>

namespace Interpreter {

using NodePtr = Pointer<Node>;

struct Constant : public Node {
    Constant(double dval) {
        value = dval;
    }
    double value;
    double calc() override {
        return value;
    }
};

struct Parenthesis : public Node {
    Parenthesis(NodePtr n) {
        node = n;
    }
    NodePtr node;
    double calc() override {
        return node->calc();
    }
    void visit(Visitor& visitor) override {
        visitor.visit(this);
        visitor.visit(node.get());
    }
};

struct UnaryOp : public Node {
    enum class Operation : uint16_t { NA = 0, Negative = 1, Positive = 2 };
    Operation op = Operation::NA;
    NodePtr node;
    double calc() override {
        switch (op) {
            case Operation::Positive: return node->calc(); break;
            case Operation::Negative: return -node->calc(); break;
        }
        return node->calc();
    }
};

struct BinaryOp : public Node {
    enum class Operation : int { NA, Addition, Subtraction, Multiplication, Division };
    static int precedence(Operation op) {
        switch (op) {
            case Operation::NA: return 0; break;
            case Operation::Addition:
            case Operation::Subtraction: return 1; break;
            case Operation::Multiplication:
            case Operation::Division: return 2; break;
        }
        return 3;
    }
    BinaryOp(Operation oper, NodePtr lhs, NodePtr rhs) {
        op = oper;
        left = lhs;
        right = rhs;
    }
    double calc() override {
        switch (op) {
            case Operation::Addition: return left->calc() + right->calc(); break;
            case Operation::Subtraction: return left->calc() - right->calc(); break;
            case Operation::Multiplication: return left->calc() * right->calc(); break;
            case Operation::Division: return left->calc() / right->calc(); break;
        }
        return 0;
    }
    void visit(Visitor& visitor) override {
        visitor.visit(left.get());
        visitor.visit(this);
        visitor.visit(right.get());
    }

    Operation op = Operation::NA;
    NodePtr left;
    NodePtr right;
};

struct Variable : public Node {
    Variable(std::string_view varname) {
        name = varname;
    }
    std::string name;
    double value;
    double calc() override {
        return value;
    }
    void visit(Visitor& visitor) {
        visitor.visit(this);
    }
};

//! Represents a function
struct Function {
    std::string name;
    size_t num_args;
    void* fnptr;
};

//! Represents a function call
struct FunctionCall : public Node {};

template <size_t N>
struct FunctionCallWithArgs : public FunctionCall {
    FunctionCallWithArgs(void* fn, const std::vector<NodePtr>& arguments) {
        fnptr = fn;
        for (unsigned j = 0; j < N; ++j) {
            args[j] = arguments[j];
        }
    }

    //! arguments
    std::array<NodePtr, N> args;

    //! the function to be called
    void* fnptr;

    double calc() override {
        std::array<double, N> values;
        for (size_t j = 0; j < N; ++j) {
            values[j] = args[j]->calc();
        }
        double value = callfn(fnptr, values.data(), N);
        return value;
    }
    void visit(Visitor& visitor) override {
        visitor.visit(this);
        for (const NodePtr& arg : args) {
            visitor.visit(arg.get());
        }
    }
};

}  // namespace Interpreter
