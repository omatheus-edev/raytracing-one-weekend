#pragma once

#include "../color.hpp"
#include "../ray.hpp"

struct HitRecord;

class Material {
public:
    virtual ~Material() = default;

    virtual bool scatter(const Ray& ray, const HitRecord& record, Color& color, Ray& scattered) const {
        return false;
    }
};
