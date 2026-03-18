#include <iostream>

#include "ElementBuffer.hpp"


ElementBuffer::ElementBuffer(GLenum vertex_usage): buffer_id(0)
                                                   , size(0)
                                                   , vertex_usage(vertex_usage) {
    create_buffer();
}

ElementBuffer::~ElementBuffer() {
    if(is_init) {
        glDeleteBuffers(1, &buffer_id);
    }
}

ElementBuffer::ElementBuffer(const void* data, std::size_t sz, GLenum vertex_usage)
        : buffer_id(0)
        , size(sz)
        , vertex_usage(vertex_usage) {
    create_buffer();
    if(!is_init) {
        std::cerr << "[ElementBuffer::ElementBuffer] : Failed to create buffer." << std::endl;
        return;
    }
    set_data(data, sz);
}

ElementBuffer::ElementBuffer(const std::vector<unsigned>& data, GLenum vertex_usage)
        : buffer_id(0)
        , size(data.size() * sizeof(unsigned))
        , vertex_usage(vertex_usage) {
    create_buffer();

    if(!is_init) {
        std::cerr << "[ElementBuffer::ElementBuffer] : Failed to create buffer." << std::endl;
        return;
    }

    set_data(data);
}

void ElementBuffer::bind() const {
    if(is_init) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
    } else {
        std::cerr << "[ElementBuffer::bind] : Attempting to bind an uninitialized buffer." << std::endl;
    }
}

void ElementBuffer::unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void ElementBuffer::set_data(const void* data, std::size_t sz) {
    if(!is_init) {
        std::cerr << "[ElementBuffer::set_data] : Attempting to set data on an uninitialized buffer." << std::endl;
        return;
    }

    bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sz, data, vertex_usage);
    size = sz;
    check_error("ElementBuffer::set_data");
    unbind();
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

void ElementBuffer::create_buffer() {
    glGenBuffers(1, &buffer_id);
    if (buffer_id > 0) {
        is_init = true;
    } else {
        std::cerr << "[ElementBuffer::create_buffer] : Failed to generate buffer." << std::endl;
    }
}

void ElementBuffer::check_error(const char* msg) const {
    if (GLenum error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error in " << msg << ": " << error << std::endl;
    }
}