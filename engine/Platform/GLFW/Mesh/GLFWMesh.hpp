#ifndef MAIN_GLFWMESH_HPP
#define MAIN_GLFWMESH_HPP

#include <glm/glm.hpp>

#include "Mesh.hpp"
#include "VertexBuffer.hpp"
#include "VertexArray.hpp"
#include "ElementBuffer.hpp"
#include "VertexLayout.hpp"
#include "GLFW.hpp"

class GLFWMesh : public Mesh {
private:
    std::unique_ptr<VertexBuffer> vertex_buffer;
    std::unique_ptr<VertexArray> vertex_array;
    std::unique_ptr<ElementBuffer> element_buffer;

    void set_up_mesh();
public:
    GLFWMesh() = default;
    GLFWMesh( std::vector<Vertex> vertices
            , std::vector<unsigned int> indices)
                    : Mesh(std::move(vertices)
                    , std::move(indices)) {
        set_up_mesh();
    }

    GLFWMesh(const GLFWMesh &) = delete;
    GLFWMesh(GLFWMesh &&) = default;
    GLFWMesh &operator=(const GLFWMesh &) = delete;
    GLFWMesh &operator=(GLFWMesh &&) = default;
    ~GLFWMesh() = default;

    void draw() const  override;
};


#endif //MAIN_GLFWMESH_HPP