#pragma once
#include <string>
#include <cmath>

namespace util {
    inline std::string repeat(const std::string& s, int n) {
        if (n <= 0) return "";

        std::string result;
        result.reserve(s.length() * n);
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }

    inline std::string separator(int width) {
        if (width <= 0) return "";
        return std::string(width, '-');
    }

    inline std::string header(const std::string& title, int width) {
        std::string padded = ' ' + title + ' ';

        // Fallback to title only if title is too wide.
        if (width < static_cast<int>(padded.length())) {
            return title;
        }
        
        // Calculate width of the two seperators. Store as float to handle odd widths.
        float seperator_width = (width - padded.length()) / 2.0f;

        return separator(std::ceil(seperator_width)) + padded + separator(std::floor(seperator_width));
    }
}