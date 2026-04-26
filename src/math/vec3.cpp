#include "math/vec3.hpp"

#include <cmath>

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator-() const {
    return {-x, -y, -z};
}

Vec3& Vec3::operator+=(const Vec3& vec) {
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

Vec3& Vec3::operator*=(double v) {
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

Vec3 &Vec3::operator/=(double v) {
    return *this *= 1/v;
}

double Vec3::length() const {
    return std::sqrt(length_squared());
}

double Vec3::length_squared() const {
    return x*x + y*y + z*z;
}
