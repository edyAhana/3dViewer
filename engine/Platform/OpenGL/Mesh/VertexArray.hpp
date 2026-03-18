#ifndef VERTEX_ARRAY_HPP
#define VERTEX_ARRAY_HPP

#include "VertexBuffer.hpp"
#include "ElementBuffer.hpp"
#include "VertexLayout.hpp"
#include "GLFW.hpp"

class VertexArray {
private:
    GLuint vao_id;
    bool is_init = false;

    void create_buffer();
    void check_error(const char* msg) const;
public:
    VertexArray();
    VertexArray(const VertexArray& other) = delete;
    VertexArray(VertexArray&& other) noexcept = default;
    VertexArray& operator=(const VertexArray& other) = delete;
    VertexArray& operator=(VertexArray&& other) noexcept = default;
    ~VertexArray();
    
    void bind() const;
    void unbind() const;

    void set_vertex_buffer(const VertexBuffer& buff, const VertexLayout& layout) const;
    void set_element_buffer(const ElementBuffer& buff) const;

    GLuint get_id() const;
};

#endif
