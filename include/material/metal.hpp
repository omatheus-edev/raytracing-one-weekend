#pragma once

#include "material/lambertian.hpp"

class Metal final : public Material {
private:
    Color albedo;

public:
    Metal(const Color& albedo);

    bool scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const override;
};