#include "material/lambertian.hpp"

#include "hittable.hpp"

Lambertian::Lambertian(const Color &albedo) : albedo(albedo) {}

bool Lambertian::scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const {
    Vec3 scatter_direction = record.normal + random_unit_vector();
    if (scatter_direction.near_zero()) {
        scatter_direction = record.normal;
    }

    scattered = Ray(record.vec, scatter_direction);
    color = albedo;
    return true;
};