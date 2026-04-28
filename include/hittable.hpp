#pragma once

#include "ray.hpp"

struct HitRecord {
public:
    Vec3 vec;
    Vec3 normal;
    double t;
};

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& ray, double ray_tmin, double ray_tmax, HitRecord& record) const = 0;
};