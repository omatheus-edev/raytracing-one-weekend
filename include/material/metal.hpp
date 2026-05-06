#pragma once

#include "material/lambertian.hpp"

class Metal final : public Material {
private:
    Color albedo;
    double fuzz;

public:
    Metal(const Color& albedo, double fuzz);

    bool scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const override;
};