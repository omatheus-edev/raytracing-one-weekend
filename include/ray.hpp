#pragma once

#include "math/vec3.hpp"

struct Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction);

    [[nodiscard]] const Vec3& getOrigin() const;

    [[nodiscard]] const Vec3& getDirection() const ;

    Vec3 at(double t) const;

private:
    Vec3 origin;
    Vec3 direction;
};