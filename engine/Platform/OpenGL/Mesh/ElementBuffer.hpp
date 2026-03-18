#ifndef ELEMENT_BUFFER_HPP
#define ELEMENT_BUFFER_HPP

#include <cstddef>
#include <vector>

#include "GLFW.hpp"

class ElementBuffer {
private:
    GLuint buffer_id;
    GLuint size;
    GLenum vertex_usage;
    bool is_init = false;

    void create_buffer();
    void check_error(const char* msg) const;
public:
    ElementBuffer(GLenum vertex_usage = GL_STATIC_DRAW);
    ElementBuffer(const void* data, std::size_t sz, GLenum vertex_usage = GL_STATIC_DRAW);
    ElementBuffer(const std::vector<unsigned>& data, GLenum vertex_usage = GL_STATIC_DRAW);
    ~ElementBuffer();

    void bind() const;
    void unbind() const;

    void set_data(const void* data, std::size_t sz) ;
    void set_data(const std::vector<unsigned>& data);

    GLuint get_id() const;
    std::size_t get_size() const;
    bool is_initialized() const { return is_init; }
};

#endif
