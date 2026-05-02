#pragma once

#include <cmath>
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