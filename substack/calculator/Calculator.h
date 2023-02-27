#include <cstdint>
#include <cstdio>
#include <cctype>
#include <string_view>
#include <stack>
#include <cmath>
#include <iostream>

#include "Pointer.h"
#include "TreeNodes.h"
#include "Predicates.h"
#include "Lexer.h"
#include "FunctionOps.h"

namespace Interpreter {

//! The Calculator has the high level grammar rules and inherits from
//! the Lexer which handles more low level char-by-char operations
struct Calculator : public Lexer {
    //! returns a node that holds a floating point value
    NodePtr dbl64() {
        if (auto dbl = parsedouble()) {
            return NodePtr(new Constant(dbl.value()));
        }
        return NodePtr();
    }

    //! Returns an expression node between parenthesis
    NodePtr parenthesis() {
        StackSaver saver(this);
        if (test(ischar('('))) {
            if (auto xp = expression()) {
                if (test(ischar(')'))) {
                    saver.commit();
                    return NodePtr(new Parenthesis(xp));
                }
            }
        }
        return NodePtr();
    }

    //! Returns a primitive node
    NodePtr primitive() {
        StackSaver saver(this);
        NodePtr lhs;
        if ((lhs = variable()) || (lhs = parenthesis()) || (lhs = dbl64())) {
            saver.commit();
        }
        return lhs;
    }

    //! Rearrange the tree such that operators will have the right precedence
    void adjustPrecedence(NodePtr& lhs, NodePtr& rhs, BinaryOp::Operation op) {
        auto binop = rhs.as<BinaryOp>();
        if (binop && (BinaryOp::precedence(binop->op) < BinaryOp::precedence(op))) {
            // Pointer<Node> tmp = binop->left;
            binop->left.reset(new BinaryOp(op, lhs, binop->left));
            lhs = rhs;
        } else {
            // Pointer<Node> tmp = lhs;
            lhs.reset(new BinaryOp(op, lhs, rhs));
        }
    }

    //! Returns an expression node, something that returns a value
    NodePtr expression() {
        StackSaver saver(this);
        skipws();
        if (auto lhs = primitive()) {
            while (auto op = arithop()) {
                if (auto rhs = expression()) {
                    adjustPrecedence(lhs, rhs, op.value());
                }
            }
            saver.commit();
            return lhs;
        }
        return {};
    }

    //! Returns a node that holds a value that can be changed
    NodePtr variable() {
        StackSaver saver(this);
        if (auto name = skip(isidentifier())) {
            Pointer<Variable>& var(_variable_map[std::string(name.value())]);
            if (!var) {
                var = new Variable(name.value());
            }
            saver.commit();
            return var;
        }
        return {};
    }

    //! Creates an AST node representing a particular call into a function
    //! with the given name and arguments. Returns a null pointer if the
    //! function name does not exist or the arguments are the wrong size
    Pointer<FunctionCall> createFunctionCall(std::string_view name,
                                             const std::vector<NodePtr>& args) {
        if (auto fn = findFunction(name)) {
            if (args.size() == fn->num_args) {
                switch (fn->num_args) {
                    case 0:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<0>(fn->fnptr, args));
                        break;
                    case 1:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<1>(fn->fnptr, args));
                        break;
                    case 2:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<2>(fn->fnptr, args));
                        break;
                    case 3:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<3>(fn->fnptr, args));
                        break;
                    case 4:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<4>(fn->fnptr, args));
                        break;
                    case 5:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<5>(fn->fnptr, args));
                        break;
                    case 6:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<6>(fn->fnptr, args));
                        break;
                    case 7:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<7>(fn->fnptr, args));
                        break;
                    case 8:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<8>(fn->fnptr, args));
                        break;
                    case 9:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<9>(fn->fnptr, args));
                        break;
                    case 10:
                        return Pointer<FunctionCall>(
                            new FunctionCallWithArgs<10>(fn->fnptr, args));
                        break;
                }
            }
        }
        return {};
    }

    //! Returns a node that holds a function with arguments
    Pointer<FunctionCall> function() {
        StackSaver saver(this);
        if (auto name = skip(isidentifier())) {
            if (test(ischar('('))) {
                std::vector<NodePtr> args;
                while (auto xp = expression()) {
                    args.push_back(xp);
                }
                if (test(ischar(')'))) {
                    if (auto fn = createFunctionCall(name.value(), args)) {
                        saver.commit();
                        return fn;
                    }
                }
            }
        }
        return {};
    }

    //! Returns a copy of the Function descriptor, if there is one
    std::optional<Function> findFunction(std::string_view name) {
        auto fn = _function_map.find(std::string(name));
        if (fn != _function_map.end()) return fn->second;
        return {};
    }

    //! A hash map to hold our variables
    using VariableMap = std::unordered_map<std::string, Pointer<Variable>>;
    VariableMap _variable_map;

    //! A hash map to hold our functions
    using FunctionMap = std::unordered_map<std::string, Function>;
    FunctionMap _function_map = {{"log", Function{"log", 1, (void*)&::log}}};

    NodePtr parse(std::string_view code) {
        reset(code);
        return expression();
    };
};

}  // namespace Interpreter