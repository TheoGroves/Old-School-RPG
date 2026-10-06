#pragma once

#include <random>
#include <cstdint>
#include <numbers>
#include <vector>
#include <stdexcept>
#include <concepts>

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

        template <typename T>
        T choice(const std::vector<T>& v) {
            if (v.empty()) {
                throw std::runtime_error("Cannot choose from an empty vector.");
            }

            return v[integer(0, v.size()-1)];
        }

        template <typename T, std::floating_point U>
        const T& choice(const std::vector<T>& v, const std::vector<U>& weights) {
            if (v.size() != weights.size()) {
                throw std::runtime_error("Cannot choose from vector as it does not have the same number of elements as weights.");
            }

            if (v.empty()) {
                throw std::runtime_error("Cannot choose from an empty vector.");
            }

            std::discrete_distribution<> dist(weights.begin(), weights.end());

            return v[dist(generator_)];
        }

        template <typename T>
        std::vector<T> choice(std::vector<T> v, size_t n) {
            if (v.size() < n) {
                throw std::runtime_error("Cannot choose from a vector that is smaller than the chosen number.");
            }

            std::vector<T> result;
            result.reserve(n);

            for (int i = 0; i < n; i++) {
                int index = integer(0, v.size()-1);
                
                result.push_back(v[index]);
                std::swap(v[index], v.back());
                v.pop_back();
            }

            return result;
        }

        float uniform(float min=0.0f, float max=1.0f) {
            std::uniform_real_distribution<float> dist(min, max);
            return dist(generator_);
        }

    private:
        std::mt19937 generator_;
    };

    inline constexpr double e = std::numbers::e;

    inline constexpr float epsilon = 0.00001f;
}