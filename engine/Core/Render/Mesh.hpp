#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <memory>

#include "Math.hpp"
#include "Material.hpp"

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
    Material material;
public:
    enum class MeshEnum {
        AXIS_X, AXIS_Y, AXIS_Z,
    };
    Mesh() = default;
    Mesh( const std::vector<Vertex>& vertices
        , const std::vector<unsigned int>& indices
        , matrix4 model
        , Material material)
                        : vertices(vertices)
                        , indices(indices)
                        , model(model)
                        , material(material){}
    virtual ~Mesh() = default;

    static std::shared_ptr<Mesh> create_cube(float width = 1);
    static std::shared_ptr<Mesh> create_sphere(float radius = 1, std::size_t segments = 32);
    static std::shared_ptr<Mesh> create_cylinder(float radius = 1, float height = 2, std::size_t segments = 32);

    virtual void draw() const = 0;
    virtual void rotate(float angle, MeshEnum axis) = 0;
    virtual void translate(const vector3& translation) = 0;
    virtual void scale(const vector3& scale) = 0;

    void use_material() const { material.get_shader_program()->use(); }

    auto& get_model() const noexcept { return model; }
    void set_model(const matrix4& new_model) noexcept { model = new_model; }
    auto& get_material() const noexcept { return material; }

    void set_vertices(const vector<Vertex>& new_vertices) { vertices = new_vertices; }
    void set_indices(const vector<unsigned int>& new_indices) { indices = new_indices; }
    void set_vertices(vector<Vertex>&& new_vertices) { vertices = std::move(new_vertices); }
    void set_indices(vector<unsigned int>&& new_indices) { indices = std::move(new_indices); }
    void set_material(const Material& new_material) { material = new_material; }
};


#endif