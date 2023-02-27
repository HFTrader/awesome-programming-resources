#pragma once
#include "TreeNodes.h"
#include <vector>
#include <cstring>
#include <cstdio>

namespace Interpreter {

struct Writer : public Visitor {
    std::vector<char> data;
    void visit(Node*) override {
    }
    void write(double value) {
        char buf[64];
        ::snprintf(buf, sizeof(buf), "%f", value);
        write(buf);
    }
    void write(std::string_view sv) {
        size_t size = data.size();
        data.resize(size + sv.size());
        memcpy(&data[size], sv.data(), sv.size());
    }
};

}  // namespace Interpreter