#include "color.hpp"

void write_color(std::ostream &out, const Color &pixel_color) {
    float r = pixel_color.x;
    float g = pixel_color.y;
    float b = pixel_color.z;
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);
    out << rbyte << " " << gbyte << " " << bbyte << "\n";
}
