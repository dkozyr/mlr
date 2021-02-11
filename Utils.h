#pragma once

#include <cmath>
#include <random>

inline const double PI = 4.0 * std::atan(1.0);

inline double Random(double a, double b) {
    static std::random_device random_device;
    static std::default_random_engine random_engine(random_device());

    std::uniform_real_distribution<double> dist(a, b);
    return dist(random_engine);
}
