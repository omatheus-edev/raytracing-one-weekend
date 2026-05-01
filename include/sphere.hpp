#pragma once

#include <cmath>
#include "hittable.hpp"
#include "math/vec3.hpp"

class Sphere : public Hittable {
private:
    Vec3 center;
    double radius;

public:
    Sphere(const Vec3& center, double radius) : center(center), radius(std::fmax(0.0, radius)) {}

    bool hit(const Ray &ray, double ray_tmin, double ray_tmax, HitRecord &record) const override;
};
