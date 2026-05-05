#include "sphere.hpp"

bool Sphere::hit(const Ray &ray, Interval interval, HitRecord &record) const {
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
    if (!interval.surrounds(root)) {
        root = (h + sqrtd) / a;
        if (!interval.surrounds(root)) {
            return false;
        }
    }

    record.t = root;
    record.vec = ray.at(record.t);
    Vec3 outward_normal = (record.vec - center) / radius;
    record.setFaceNormal(ray, outward_normal);
    record.material = material;
    return true;
}
