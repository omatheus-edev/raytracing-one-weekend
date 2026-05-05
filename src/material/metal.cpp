#include "material/metal.hpp"

#include "hittable.hpp"

Metal::Metal(const Color &albedo) : albedo(albedo) {}

bool Metal::scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const {
    Vec3 reflected = reflect(ray.getDirection(), record.normal);
    scattered = Ray(record.vec, reflected);
    color = albedo;
    return true;
}
