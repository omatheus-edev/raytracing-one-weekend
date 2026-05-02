#include "hittable.hpp"

void HitRecord::setFaceNormal(const Ray &ray, const Vec3 &outwardNormal) {
    if (dot(ray.getDirection(), outwardNormal) > 0.0) {
        normal = -outwardNormal;
        frontFace = false;
    } else {
        normal = outwardNormal;
        frontFace = true;
    }
}