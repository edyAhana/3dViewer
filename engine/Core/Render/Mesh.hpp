#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <memory>

using std::vector;

class Mesh {
protected:
    struct Vertex {
        float x, y, z, r, g, b;
    };
protected:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
public:
    Mesh() = default;
    Mesh( std::vector<Vertex>&& vertices
              , std::vector<unsigned int>&& indices)
                        : vertices(std::move(vertices))
                        , indices(std::move(indices)) {}
    virtual ~Mesh() = default;

    static std::shared_ptr<Mesh> create_cube(std::size_t width = 1);
    static std::shared_ptr<Mesh> create_sphere(std::size_t radius = 1, std::size_t segments = 32);
    static std::shared_ptr<Mesh> create_cylinder(std::size_t radius = 1, std::size_t height = 2, std::size_t segments = 32);

    virtual void draw() const = 0;
};


#endif