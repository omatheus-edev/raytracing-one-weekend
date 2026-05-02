#pragma once
#include <memory>
#include <vector>
#include "hittable.hpp"

struct HittableList : public Hittable {
public:
    std::vector<std::shared_ptr<Hittable>> objects;

    HittableList() = default;

    HittableList(std::shared_ptr<Hittable> object);

    void clear();

    void add(std::shared_ptr<Hittable> object);

    bool hit(const Ray &ray, double ray_tmin, double ray_tmax, HitRecord &record) const override;
};
