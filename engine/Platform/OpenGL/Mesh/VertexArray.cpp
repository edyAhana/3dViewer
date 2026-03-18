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
    create_buffer();
    if(!is_init) {
        std::cerr << "[VertexArray::VertexArray] : Failed to create vertex array object." << std::endl;
    }
}

VertexArray::~VertexArray() {
    if(is_init) {
        glDeleteVertexArrays(1, &vao_id);
    }
}

void VertexArray::bind() const {
    if(is_init) {
        glBindVertexArray(vao_id);
    } else {
        std::cerr << "[VertexArray::bind] : Attempting to bind an uninitialized vertex array object." << std::endl;
    }
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::set_vertex_buffer(const VertexBuffer& buff, const VertexLayout& layout)  const{
    if(!is_init || !buff.is_initialized()) {
        std::cerr << "[VertexArray::set_vertex_buffer] : Attempting to set vertex buffer on an uninitialized vertex array object or using an uninitialized vertex buffer." << std::endl;
        return;
    }

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
        check_error("VertexArray::set_vertex_buffer");
    }
    buff.unbind();
    unbind();
}

void VertexArray::set_element_buffer(const ElementBuffer& buff) const {
    if(!is_init || !buff.is_initialized()) {
        std::cerr << "[VertexArray::set_element_buffer] : Attempting to set element buffer on an uninitialized vertex array object or using an uninitialized element buffer." << std::endl;
        return;
    }

    bind();
    buff.bind();
    check_error("VertexArray::set_element_buffer");
    unbind();
}

GLuint VertexArray::get_id() const {
    return vao_id;
}

void VertexArray::create_buffer() {
    glGenVertexArrays(1, &vao_id);
    if (vao_id > 0) {
        is_init = true;
    }
}

void VertexArray::check_error(const char* msg) const {
    if (GLenum error = glGetError(); error != GL_NO_ERROR) {
        std::cerr << "OpenGL error in " << msg << ": " << error << std::endl;
    }
}
