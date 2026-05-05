#pragma once

#include <cmath>
#include "hittable.hpp"
#include "math/vec3.hpp"

class Sphere : public Hittable {
private:
    Vec3 center;
    double radius;
    std::shared_ptr<Material> material;

public:
    Sphere(const Vec3& center, double radius) : center(center), radius(std::fmax(0.0, radius)) {}

    bool hit(const Ray &ray, Interval interval, HitRecord &record) const override;
};
