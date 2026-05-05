#pragma once

#include "material/material.hpp"

class Lambertian final : public Material {
private:
    Color albedo;

public:
    Lambertian(const Color& albedo);

    bool scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const override;
};