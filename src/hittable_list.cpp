#include "hittable_list.hpp"

HittableList::HittableList(std::shared_ptr<Hittable> object) {
    add(object);
}

void HittableList::clear() {
    objects.clear();
}

void HittableList::add(std::shared_ptr<Hittable> object) {
    objects.push_back(object);
}

bool HittableList::hit(const Ray &ray, double ray_tmin, double ray_tmax, HitRecord &record) const {
    HitRecord temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_tmax;

    for (const std::shared_ptr<Hittable>& object : objects) {
        if (object->hit(ray, ray_tmin, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            record = temp_rec;
        }
    }
    return hit_anything;
}
