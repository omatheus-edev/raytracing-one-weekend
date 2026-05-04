#pragma once

#include <cmath>
#include <iostream>

struct Vec3 {
    static Vec3 random();

    static Vec3 random(double min, double max);

    double x;
    double y;
    double z;

    Vec3() = default;

    Vec3(double x, double y, double z);

    Vec3 operator-() const;

    Vec3& operator+=(const Vec3& vec);

    Vec3& operator*=(double v);

    Vec3& operator/=(double v);

    [[nodiscard]] double length() const;

    [[nodiscard]] double length_squared() const;
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& vec) {
    return out << vec.x << " " << vec.y << " " << vec.z;
}

inline Vec3 operator+(const Vec3& vec, const Vec3& other) {
    return Vec3(vec.x + other.x, vec.y + other.y, vec.z + other.z);
}

inline Vec3 operator-(const Vec3& vec, const Vec3& other) {
    return Vec3(vec.x - other.x, vec.y - other.y, vec.z - other.z);
}

inline Vec3 operator*(const Vec3& vec, const Vec3& other) {
    return Vec3(vec.x * other.x, vec.y * other.y, vec.z * other.z);
}

inline Vec3 operator*(double value, const Vec3& vec) {
    return Vec3(vec.x * value, vec.y * value, vec.z * value);
}

inline Vec3 operator*(const Vec3& vec, double value) {
    return value * vec;
}

inline Vec3 operator/(const Vec3& vec, double value) {
    return (1/value) * vec;
}

inline double dot(const Vec3& vec, const Vec3& other) {
    return vec.x * other.x +
            vec.y * other.y +
            vec.z * other.z;
}

inline Vec3 cross(const Vec3& vec, const Vec3& other) {
    return Vec3(vec.y * other.z - vec.z * other.y,
                vec.z * other.x - vec.x * other.z,
                vec.x * other.y - vec.y * other.x);
}

inline Vec3 normalize(const Vec3& vec) {
    return vec / vec.length();
}

inline Vec3 random_unit_vector() {
    while (true) {
        Vec3 p = Vec3::random(-1, 1);
        double lensq = p.length_squared();
        if (1e-160 < lensq && lensq <= 1) {
            return p / std::sqrt(lensq);
        }
    }
}

inline Vec3 random_on_hemisphere(const Vec3& normal) {
    Vec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) {
        return on_unit_sphere;
    } else {
        return -on_unit_sphere;
    }
}