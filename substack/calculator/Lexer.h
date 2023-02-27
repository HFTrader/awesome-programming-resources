#pragma once

#include "Pointer.h"
#include "TreeNodes.h"

#include <string_view>
#include <stack>
#include <optional>

namespace Interpreter {

//! Not technically a lexer but it takes care of the basic token
//! types like numbers
struct Lexer : public RefCounted {
    //! Just a type shortener
    using sviterator = std::string_view::iterator;

    Lexer() {
    }

    //! Resets the code and parser position
    void reset(std::string_view str) {
        code = str;
        it = code.begin();
    }

    //! The string with the expression to be parsed
    std::string_view code;

    //! The current position of the parser
    sviterator it;

private:
    //! A stack to restore positions in case of failure
    //! Being private will force the use of StackSaver (preferred)
    std::stack<sviterator> stack;

    //! Saves the current iterator and returns it
    sviterator save() {
        stack.push(it);
        return it;
    }
    //! Discards the top stack, committing the iterator as consequence
    sviterator commit() {
        sviterator tmp = stack.top();
        stack.pop();
        return tmp;
    }
    //! Restores the top of the stack as the current iterator. Returns the old current
    sviterator restore() {
        sviterator tmp = it;
        it = stack.top();
        stack.pop();
        return tmp;
    }

public:
    friend class StackSaver;

    //! Restores the stack if not committed before destruction
    struct StackSaver {
        StackSaver(Lexer* lexer) : _lexer(lexer) {
            _lexer->save();
            _committed = false;
        }
        void commit() {
            _committed = true;
        }
        ~StackSaver() {
            if (_committed)
                _lexer->commit();
            else
                _lexer->restore();
        }
        bool _committed;
        Lexer* _lexer;
    };

    //! Test a single character for a condition
    template <typename Fn>
    std::optional<char> test(Fn&& fn) {
        if (it != code.end()) {
            if (fn(*it)) {
                return *it++;
            }
        }
        return {};
    };

    //! Skips until fn is false, returning the string if it's non-empty
    template <typename Fn>
    std::optional<std::string_view> skip(Fn&& fn) {
        sviterator start = it;
        for (; it != code.end(); ++it) {
            if (!fn(*it)) break;
        }
        if (it == start) return {};
        return std::string_view{start, size_t(it - start)};
    };

    size_t svtoul(std::string_view sv) {
        size_t ival = 0;
        for (char ch : sv) {
            ival = 10 * ival + (ch - '0');
        }
        return ival;
    }

    //! Parses an unsigned integer
    std::optional<size_t> parseuint() {
        if (auto s = skip(isdigit())) {
            return {svtoul(s.value())};
        }
        return {};
    }

    //! Parses a signed integer
    std::optional<ssize_t> parseint() {
        save();
        bool neg = false;
        if (auto sgn = test(isany("+-"))) {
            neg = sgn.value() == '-';
        }
        if (auto uval = parseuint()) {
            ssize_t ival = uval.value();
            return neg ? -ival : ival;
        }
        restore();
        return {};
    }

    //! Skips whitespace
    std::optional<std::string_view> skipws() {
        return skip(isspace());
    }

    //! Power of 10 of a number
    static size_t ipow10(size_t val, size_t iexp) {
        for (; iexp > 0; --iexp) val = val * 10;
        return val;
    }
    //! Parses a double
    std::optional<double> parsedouble() {
        save();
        bool neg = false;
        if (auto sgn = test(isany("+-"))) {
            neg = sgn.value() == '-';
        }
        if (auto sint = skip(isdigit())) {
            size_t ival = svtoul(sint.value());  // convert the integer part
            if (test(ischar('.'))) {
                if (auto sfrac = skip(isdigit())) {       // we have digits after period
                    size_t fval = svtoul(sfrac.value());  // convert the fractional
                    ssize_t len = sfrac.value().size();   // used as exponent below
                    ival = ipow10(ival, len);             // scale the whole part
                    double dval =
                        (ival + fval) * pow(10, -len);  // compute the power of 10
                    commit();
                    return neg ? -dval : dval;
                }
            }
            // Just convert to double
            double dval = ival;
            commit();
            return neg ? -dval : dval;
        }
        restore();
        return {};
    }

    //! Returns an arithmetic operator
    std::optional<BinaryOp::Operation> arithop() {
        if (auto s = test(isany("-+*/"))) {
            switch (s.value()) {
                case '+': return BinaryOp::Operation::Addition; break;
                case '-': return BinaryOp::Operation::Subtraction; break;
                case '*': return BinaryOp::Operation::Multiplication; break;
                case '/': return BinaryOp::Operation::Division; break;
            }
        }
        return {};
    }
};

}  // namespace Interpreter
