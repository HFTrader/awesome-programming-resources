#pragma once

#include <cstddef>
#include <string_view>

namespace Interpreter {

struct isidentifier {
    bool operator()(char ch) {
        if (counter++ == 0) return (ch == '_') || (std::isalpha(ch) != 0);
        return (ch == '_') || (std::isalnum(ch) != 0);
    }
    int counter = 0;
};

struct isalpha {
    bool operator()(char ch) {
        return (std::isalpha(ch) != 0);
    }
};

struct isdigit {
    bool operator()(char ch) {
        return (std::isdigit(ch) != 0);
    }
};
struct isalnum {
    bool operator()(char ch) {
        return (std::isalnum(ch) != 0);
    }
};
struct isspace {
    bool operator()(char ch) {
        return (std::isspace(ch) != 0);
    }
};

struct ischar {
    ischar(char ch) : c(ch) {
    }
    bool operator()(char ch) const {
        return (ch == c);
    }
    char c;
};

struct isany {
    isany(std::string_view sv) : _sv(sv) {
    }
    bool operator()(char ch) const {
        for (char c : _sv) {
            if (c == ch) return true;
        }
        return false;
    }
    std::string_view _sv;
};

}  // namespace Interpreter
