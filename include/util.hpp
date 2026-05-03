#pragma once

#include <cmath>
#include <random>
#include <memory>
#include <iostream>
#include <memory>
#include "color.hpp"
#include "ray.hpp"
#include "math/vec3.hpp"
#include "interval.hpp"

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.1415926535897932385;

inline double degress_to_radians(double degress) {
    return degress * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    return min + (max-min) * random_double();
}