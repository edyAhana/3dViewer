#include <vector>
#include <iostream>

#include "VertexBuffer.hpp"

VertexBuffer::VertexBuffer(GLenum vertex_usage): buffer_id(0)
                                               , size(0)
                                               , vertex_usage(vertex_usage) {
    create_buffer();
}

VertexBuffer::VertexBuffer(const void* data, std::size_t sz, GLenum vertex_usage)
        : buffer_id(0)
        , size(sz)
        , vertex_usage(vertex_usage) {
    create_buffer();

    if(!is_init) {
        std::cerr << "[VertexBuffer::VertexBuffer] : Failed to create buffer." << std::endl;
        return;
    }

    set_data(data, sz);
}

VertexBuffer::VertexBuffer(const std::vector<float>& data, GLenum vertex_usage)
        : buffer_id(0)
        , size(data.size() * sizeof(float))
        , vertex_usage(vertex_usage) {
    create_buffer();

    if(!is_init) {
        std::cerr << "[VertexBuffer::VertexBuffer] : Failed to create buffer." << std::endl;
        return;
    }

    set_data(data);
}

VertexBuffer::~VertexBuffer() {
    if(is_init) {
        glDeleteBuffers(1, &buffer_id);
    }
}

void VertexBuffer::bind() const {
    if(is_init) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    } else {
        std::cerr << "[VertexBuffer::bind] : Attempting to bind an uninitialized buffer." << std::endl;
    }
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::set_data(const void* date, std::size_t sz){
    if(!is_init) {
        std::cerr << "[VertexBuffer::set_data] : Attempting to set data on an uninitialized buffer." << std::endl;
        return;
    }

    bind();
    glBufferData(GL_ARRAY_BUFFER, sz, date, vertex_usage);
    size = sz;
    check_error("VertexBuffer::set_data");
    unbind();
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

void VertexBuffer::create_buffer() {
    glGenBuffers(1, &buffer_id);
    if(buffer_id == 0) {
        std::cerr << "[VertexBuffer::create_buffer] : Failed to generate buffer." << std::endl;
        is_init = false;
    } else {
        is_init = true;
    }
}

void VertexBuffer::check_error(const char* msg) const {
    if(GLenum error = glGetError() ; error != GL_NO_ERROR) {
        std::cerr << "[VertexBuffer::check_error] : [" << msg << "] : " << error << std::endl;
    }
}