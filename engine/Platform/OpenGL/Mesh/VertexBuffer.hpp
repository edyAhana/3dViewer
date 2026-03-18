#ifndef VERTEX_BUFFER_HPP
#define VERTEX_BUFFER_HPP

#include <vector>
#include <filesystem>
#include <optional>

#include "VertexLayout.hpp"
#include "GLFW.hpp"

using Path = std::filesystem::path;

class VertexBuffer {
private:
    GLuint buffer_id;
    GLuint size;
    GLenum vertex_usage;
    bool is_init = false;

    void create_buffer();
    void check_error(const char* msg) const;

public:
    VertexBuffer(GLenum vertex_usage = GL_STATIC_DRAW);
    VertexBuffer(const void* data, std::size_t sz, GLenum vertex_usage = GL_STATIC_DRAW);
    VertexBuffer(const std::vector<float>& data, GLenum vertex_usage = GL_STATIC_DRAW);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

    void set_data(const void* date, std::size_t sz);
    void set_data(const std::vector<float>& date);

    GLuint get_id() const;
    std::size_t get_size() const;
    bool is_initialized() const { return is_init; }
};



#endif
