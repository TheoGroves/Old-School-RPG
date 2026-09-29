#pragma once

#include <random>
#include <cstdint>
#include <numbers>

namespace maths {
    class Random {
    public:
        Random(std::uint32_t seed)
            : generator_(seed) {}

        int integer(int min, int max) {
            std::uniform_int_distribution<int> dist(min, max);
            return dist(generator_);
        }

        double normal(double mean, double standard_deviation) {
            std::normal_distribution<double> dist(mean, standard_deviation);
            return dist(generator_);
        }

    private:
        std::mt19937 generator_;
    };

    inline constexpr double e = std::numbers::e;


}