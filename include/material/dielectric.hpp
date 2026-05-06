#pragma once

#include "material.hpp"
#include "material/dielectric.hpp"

class Dielectric final : public Material {
private:
    static double reflectance(double cosine, double refraction_index);

    double refraction_index;

public:
    Dielectric(double refraction_index);

    bool scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const override;
};