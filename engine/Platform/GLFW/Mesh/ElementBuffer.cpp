#include <iostream>

#include "ElementBuffer.hpp"


ElementBuffer::ElementBuffer(GLenum vertex_usage): buffer_id(0)
                                                   , size(0)
                                                   , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
}

ElementBuffer::~ElementBuffer() {
    if (buffer_id > 0) {
        glDeleteBuffers(1, &buffer_id);
        buffer_id = 0;
        size = 0;
    }
}

ElementBuffer::ElementBuffer(const void* data, std::size_t sz, GLenum vertex_usage)
        : buffer_id(0)
        , size(sz)
        , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
    bind();
    set_data(data, sz);
    unbind();
}

ElementBuffer::ElementBuffer(const std::vector<unsigned>& data, GLenum vertex_usage)
        : buffer_id(0)
        , size(data.size() * sizeof(unsigned))
        , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
    bind();
    set_data(data);
    unbind();
}

void ElementBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
}

void ElementBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::set_data(const void* data, std::size_t sz) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, vertex_usage);
    size = sz;

    if (GLenum error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error in ElementBuffer::setData: " << error << std::endl;
    }
}

void ElementBuffer::set_data(const std::vector<unsigned>& data) {
    set_data(data.data(), data.size() * sizeof(unsigned));
}

GLuint ElementBuffer::get_id() const {
    return buffer_id;
}
std::size_t ElementBuffer::get_size() const {
    return size;
}
