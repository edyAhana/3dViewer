#include <iostream>

#include "ShaderProgram.hpp"
#include "GLFW.hpp"

ShaderProgram::ShaderProgram(): id(0) {}
ShaderProgram::~ShaderProgram() {
    if(id == 0) {
        glDeleteProgram(id);
    }
}

void ShaderProgram::init() {
    id = glCreateProgram();
}

void ShaderProgram::attach_shader(const Shader& shader) const {
    if(id == 0) {
        std::cerr << "[ShaderProgram::attach_shader] : Program is not created." << std::endl;
        return;
    }

    if(shader.get_id() == 0 && !shader.compile_shader()) {
        std::cerr << "[ShaderProgram::attach_shader] : Failed to compile shader." << std::endl;
        return;
    }

    glAttachShader(id, shader.get_id());
}

bool ShaderProgram::link_program() const  {
    if(id == 0) {
        std::cerr << "[ShaderProgram::link_program] : Program is not created." << std::endl;
        return false;
    }

    glLinkProgram(id);

    GLint success;
    GLchar infolog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);

    if (!success) {
        std::cerr << "[ShaderProgram::link_program] : Failed to link program." << std::endl;
        glGetProgramInfoLog(id, 512, NULL, infolog);
        std::cerr << infolog << std::endl;
        return false;
    }
    
    return true;
}

void ShaderProgram::use() const {
    if(id == 0) {
        std::cerr << "[ShaderProgram::use] : Program is not created." << std::endl;
        return;
    }

    glUseProgram(id);
}

bool ShaderProgram::set_uniform_matrix4(const std::string& name, const matrix4& value) const {
    if(id == 0) {
        std::cerr << "[ShaderProgram::set_uniform_matrix4] : Program is not created." << std::endl;
        return false;
    }

    GLint location = glGetUniformLocation(id, name.c_str());

    if(location == -1) {
        std::cerr << "[ShaderProgram::set_uniform_matrix4] : Failed to find uniform location." << std::endl;
        return false;
    }

    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    return true;
}

bool ShaderProgram::set_uniform_vec3(const std::string& name, const vector3& value) const {
    if(id == 0) {
        std::cerr << "[ShaderProgram::set_uniform_vec3] : Program is not created." << std::endl;
        return false;
    }

    GLint location = glGetUniformLocation(id, name.c_str());

    if(location == -1) {
        std::cerr << "[ShaderProgram::set_uniform_vec3] : Failed to find uniform location." << std::endl;
        return false;
    }

    glUniform3fv(location, 1, glm::value_ptr(value));
    return true;
}