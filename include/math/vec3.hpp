#pragma once

#include <iostream>

struct Vec3 {
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