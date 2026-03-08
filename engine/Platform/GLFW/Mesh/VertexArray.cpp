#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexArray.hpp"

#include <iostream>
#include <ostream>

#include "GLFW.hpp"

std::size_t convert_type_to_size(GLenum type) {
    switch (type) {
        case GL_FLOAT:
            return sizeof(GLfloat);
        case GL_DOUBLE:
            return sizeof(double);
        case GL_INT:
            return sizeof(int);
    }
    return sizeof(GLfloat);
}

VertexArray::VertexArray() {
    glGenVertexArrays(1, &vao_id);
    if (vao_id == 0) {
        std::cerr << "[VertexArray::VertexArray] Failed to create VAO." << std::endl;
    }
}

VertexArray::~VertexArray() {
    if (vao_id > 0) {
        glDeleteVertexArrays(1, &vao_id);
    }
}

void VertexArray::bind() const {
    glBindVertexArray(vao_id);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::set_vertex_buffer(const VertexBuffer& buff, const VertexLayout& layout)  const{
    bind();
    buff.bind();

    for (std::size_t i = 0; i < layout.get_size(); ++i) {
        glVertexAttribPointer(i
                             , layout[i].size
                             , layout[i].type
                             , layout[i].normalized
                             , layout.get_step()
                             , reinterpret_cast<const GLvoid*>(layout[i].offset)
                             );
        glEnableVertexAttribArray(i);
        if (GLenum error = glGetError(); error != GL_NO_ERROR) {
            std::cerr << "OpenGL error in vertex attribute " << i << ": " << error << std::endl;
        }
    }
    buff.unbind();
    unbind();
}

void VertexArray::set_element_buffer(const ElementBuffer& buff) const {
    bind();
    buff.bind();
    if (GLenum error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error in element attribute "  << error << std::endl;
    }
    unbind();
}

GLuint VertexArray::get_id() const {
    return vao_id;
}

#endif
