#include "sphere.hpp"

bool Sphere::hit(const Ray &ray, double ray_tmin, double ray_tmax, HitRecord &record) const {
    Vec3 oc = center - ray.getOrigin();
    double a = ray.getDirection().length_squared();
    double h = dot(ray.getDirection(), oc);
    double c = oc.length_squared() - radius * radius;
    double discriminant = h * h - a * c;

    if (discriminant < 0) {
        return false;
    }
    double sqrtd = std::sqrt(discriminant);
    double root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
            return false;
        }

        record.t = root;
        record.vec = ray.at(record.t);
        record.normal = (record.vec - center) / radius;
        return true;
    }
}
