#pragma once

#include "ray.hpp"

struct HitRecord {
public:
    Vec3 vec;
    Vec3 normal;
    double t;
    bool frontFace;

    HitRecord();

    void setFaceNormal(const Ray& ray, const Vec3& outwardNormal);
};

class Hittable {
public:
    virtual ~Hittable() = default;

    virtual bool hit(const Ray& ray, double ray_tmin, double ray_tmax, HitRecord& record) const = 0;
};