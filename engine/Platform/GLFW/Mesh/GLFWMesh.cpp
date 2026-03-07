#include "GLFWMesh.hpp"

void GLFWMesh::set_up_mesh() {
    vertex_buffer = std::make_unique<VertexBuffer>(vertices.data(), vertices.size() * sizeof(Vertex));
    element_buffer = std::make_unique<ElementBuffer>(indices.data(), indices.size() * sizeof(unsigned int));
    vertex_array = std::make_unique<VertexArray>();

    VertexLayout layout;
    layout.push<float>(3);
    layout.push<float>(3);

    vertex_array->set_vertex_buffer(*vertex_buffer, layout);

    if (element_buffer != nullptr && element_buffer->get_size() != 0) {
        vertex_array->set_element_buffer(*element_buffer);
    }
}

void GLFWMesh::draw() const {
    vertex_array->bind();
    if (element_buffer != nullptr && element_buffer->get_size() != 0) {
        glDrawElements(GL_TRIANGLES, element_buffer->get_size() / 3, GL_UNSIGNED_INT, nullptr);
        return;
    }
    glDrawArrays(GL_TRIANGLES, 0, vertex_buffer->get_size() / 6);
    vertex_array->unbind();
}