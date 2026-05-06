#include "material/dielectric.hpp"

#include "hittable.hpp"
#include "util.hpp"

Dielectric::Dielectric(double refraction_index) : refraction_index(refraction_index) {}

double Dielectric::reflectance(double cosine, double refraction_index) {
    double r0 = (1 - refraction_index) / (1 + refraction_index);
    r0 = r0 * r0;
    return r0 + (1-r0)*std::pow((1 - cosine),5);
}

bool Dielectric::scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const {
    color = Color(1, 1, 1);
    double ri = record.frontFace ? (1.0 / refraction_index) : refraction_index;
    Vec3 unit_direction = normalize(ray.getDirection());
    double cos_theta = std::fmin(dot(-unit_direction, record.normal), 1.0);
    double sin_theta = std::sqrt(1.0 - cos_theta * cos_theta);
    bool cannot_refract = ri * sin_theta > 1.0;
    Vec3 direction;

    if (cannot_refract || reflectance(cos_theta, ri) > random_double()) {
        direction = reflect(unit_direction, record.normal);
    } else {
        direction = refract(unit_direction, record.normal, ri);
    }
    scattered = Ray(record.vec, direction);
    return true;
}
