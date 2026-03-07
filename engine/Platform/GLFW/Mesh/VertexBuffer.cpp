#include <vector>
#include <iostream>

#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(GLenum vertex_usage): buffer_id(0)
                                                 , size(0)
                                                 , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
}

VertexBuffer::VertexBuffer(const void* data, std::size_t sz, GLenum vertex_usage)
        : buffer_id(0)
        , size(sz)
        , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
    set_data(data, sz);
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, GLenum vertex_usage)
        : buffer_id(0)
        , size(data.size() * sizeof(float))
        , vertex_usage(vertex_usage) {
    glGenBuffers(1, &buffer_id);
    set_data(data);
}

VertexBuffer::~VertexBuffer() {
    if (buffer_id > 0) {
        glDeleteBuffers(1, &buffer_id);
        buffer_id = 0;
        size = 0;
    }
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::set_data(const void* date, std::size_t sz){
    glBufferData(GL_ARRAY_BUFFER, sz, date, vertex_usage);
    size = sz;

    if (GLenum error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error in VertexBuffer::setData: " << error << std::endl;
    }
} 

void VertexBuffer::set_data(const std::vector<float>& date) {
    set_data(date.data(), date.size() * sizeof(double));
}

GLuint VertexBuffer::get_id() const {
    return buffer_id;
}
std::size_t VertexBuffer::get_size() const {
    return size;
}
