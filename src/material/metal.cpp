#include "material/metal.hpp"

#include "hittable.hpp"

Metal::Metal(const Color &albedo, double fuzz) : albedo(albedo), fuzz(fuzz < 1 ? fuzz : 1) {}

bool Metal::scatter(const Ray &ray, const HitRecord &record, Color &color, Ray &scattered) const {
    Vec3 reflected = reflect(ray.getDirection(), record.normal);
    reflected = normalize(reflected) + (fuzz * random_unit_vector());
    scattered = Ray(record.vec, reflected);
    color = albedo;
    return (dot(scattered.getDirection(), record.normal) > 0);
}
