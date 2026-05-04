#include "util.hpp"
#include "sphere.hpp"
#include "hittable_list.hpp"
#include "camera.hpp"

int main() {
    HittableList world;
    world.add(std::make_shared<Sphere>(Vec3(0,0,-1), 0.5));
    world.add(std::make_shared<Sphere>(Vec3(0,-100.5,-1), 100));

    Camera camera;
    camera.aspect_ratio = 16.0 / 9.0;
    camera.image_width = 400;
    camera.samples_per_pixel = 100;
    camera.max_depth = 50;
    camera.render(world);
    return 0;
}
