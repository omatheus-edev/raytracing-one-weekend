#include "color.hpp"

#include "interval.hpp"

void write_color(std::ostream &out, const Color &pixel_color) {
    float r = pixel_color.x;
    float g = pixel_color.y;
    float b = pixel_color.z;
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);
    static const Interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));
    out << rbyte << " " << gbyte << " " << bbyte << "\n";
}