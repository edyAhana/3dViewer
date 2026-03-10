#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <memory>

#include "Math.hpp"

using std::vector;

class Mesh {
protected:
    struct Vertex {
        float x, y, z, r, g, b;
    };
protected:
    vector<Vertex> vertices;
    vector<unsigned int> indices;

    matrix4 model;
public:
    enum class MeshEnum {
        AXIS_X, AXIS_Y, AXIS_Z,
    };
    Mesh() = default;
    Mesh( const std::vector<Vertex>& vertices
              , const std::vector<unsigned int>& indices
              , matrix4 model)
                        : vertices(vertices)
                        , indices(indices)
                        , model(model){}
    virtual ~Mesh() = default;

    static std::shared_ptr<Mesh> create_cube(std::size_t width = 1);
    static std::shared_ptr<Mesh> create_sphere(std::size_t radius = 1, std::size_t segments = 32);
    static std::shared_ptr<Mesh> create_cylinder(std::size_t radius = 1, std::size_t height = 2, std::size_t segments = 32);

    virtual void draw() const = 0;
    virtual void rotate(float angle, MeshEnum axis) = 0;
    virtual void translate(const vector3& translation) = 0;
    virtual void scale(const vector3& scale) = 0;

    auto get_model() const noexcept { return model; }
};


#endif