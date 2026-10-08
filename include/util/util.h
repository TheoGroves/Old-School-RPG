#pragma once
#include <string>
#include <cmath>
#include <memory>
#include <concepts>
#include <format>
#include <iostream>
#include <limits>
#include <string_view>
#include <sstream>
#include <thread>
#include <chrono>

namespace util {
    constexpr int separator_size = 50;

    inline void print(std::string_view s) {
        int delay = 10;

        for (char c : s) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
    }

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
        
        // Calculate width of the two separators. Store as float to handle odd widths.
        float separator_width = (width - padded.length()) / 2.0f;

        return separator(std::ceil(separator_width)) + padded + separator(std::floor(separator_width));
    }

    template <typename T>
    inline T prompt(std::string_view prompt) {
        T choice;
        while (true) {
            print(std::format("{}\n> ", prompt));

            std::string line;
            std::getline(std::cin, line);

            std::istringstream iss(line);

            if (iss >> choice && iss.eof()) {
                return choice;
            }
        }
    }

    template <std::integral T>
    inline T prompt(std::string_view prompt, T min, T max) {
        T choice;
        while (true) {
            print(std::format("{} ({}-{})\n> ", prompt, min, max));

            std::string line;
            std::getline(std::cin, line);

            std::istringstream iss(line);

            if (iss >> choice && iss.eof() && choice >= min && choice <= max) {
                return choice;
            }
        }
    }

    template <typename T>
    concept formattable = requires(T a) {
        std::format("{}", a);
    };

    template <typename T>
    inline void display_vector(const std::vector<T>& v) {
        for (size_t i = 0; i < v.size(); ++i) {
            print(std::format("{}. {}\n", i+1, v[i]));
        }
    }

    template <typename T>
    inline void display_vector(const std::vector<T>& v)
        requires (requires(T ptr) { *ptr; }) // Check if T can be dereferenced
    {
        for (size_t i = 0; i < v.size(); ++i) {
            if (v[i]) {
                if constexpr (requires { v[i]->get_display_name(); }) {
                    print(std::format("{}. {}\n", i+1, v[i]->get_display_name()));
                }
                else if constexpr (requires { std::format("{}", *v[i]); }) {
                    print(std::format("{}. {}", i+1, *v[i]));
                } else {
                    print(std::format("{}. [Unformattable Ptr]\n", i+1));
                }
            } else {
                print(std::format("{}. [Null]\n", i+1));
            }
        }
    }

    template <typename T, typename U>
    T* as(const std::unique_ptr<U>& ptr) {
        return dynamic_cast<T*>(ptr.get());
    }
}