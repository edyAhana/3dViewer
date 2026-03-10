#ifndef MAIN_GLFWMESH_HPP
#define MAIN_GLFWMESH_HPP


#include "Math.hpp"
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
    GLFWMesh( const std::vector<Vertex>& vertices
            , const std::vector<unsigned int>& indices = std::vector<unsigned int>()
            , matrix4 model = matrix4(1))
                    : Mesh( vertices
                          , indices
                          , model   ) {
        set_up_mesh();
    }

    GLFWMesh(const GLFWMesh &) = delete;
    GLFWMesh(GLFWMesh &&) = default;
    GLFWMesh &operator=(const GLFWMesh &) = delete;
    GLFWMesh &operator=(GLFWMesh &&) = default;
    ~GLFWMesh() = default;

    void draw() const  override;
    void rotate(float angle, MeshEnum axis) override;
    void translate(const vector3& translation) override;
    void scale(const vector3& scale) override;
};


#endif //MAIN_GLFWMESH_HPP