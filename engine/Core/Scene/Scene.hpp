#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include <memory>

#include "Mesh.hpp"
#include "Camera.hpp"

class Scene {
private:
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::shared_ptr<Camera> camera;
public:
    Scene() = default;
    Scene(std::shared_ptr<Camera> cam) : camera(std::move(cam)) {}

    void add_mesh(std::shared_ptr<Mesh> mesh) {
        meshes.push_back(std::move(mesh));
    }

    const std::vector<std::shared_ptr<Mesh>>& get_meshes() const {
        return meshes;
    }

    Camera& get_camera() {
        return *camera;
    }
};

#endif // SCENE_HPP