#pragma once

#include "math/vec3.hpp"

using Color = Vec3;

void write_color(std::ostream& out, const Color& pixel_color);

inline double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return std::sqrt(linear_component);

    return 0;
}