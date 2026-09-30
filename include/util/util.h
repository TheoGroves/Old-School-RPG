#pragma once
#include <string>

namespace util {
    static std::string repeat(const std::string& s, int n) {
        std::string result;
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }
}