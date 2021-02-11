#pragma once

#include <cmath>
#include <random>

inline double Random(double a, double b) {
    static std::random_device random_device;
    static std::default_random_engine random_engine(random_device());

    std::uniform_real_distribution<double> dist(a, b);
    return dist(random_engine);
}
