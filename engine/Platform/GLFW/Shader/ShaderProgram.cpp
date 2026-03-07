#include <iostream>

#include "ShaderProgram.hpp"
#include "GLFW.hpp"

ShaderProgram::ShaderProgram(): id(0) {}
ShaderProgram::~ShaderProgram() {}

void ShaderProgram::init() {
    id = glCreateProgram();
}

void ShaderProgram::attach_shader(const Shader& shader) const {
    if(id == 0) {
        std::cerr << "*** PROGRMA IS NOT CREATED ***" << std::endl;
        return;
    }

    if(shader.get_id() == 0 && !shader.compile_shader()) {
        std::cerr << "*** SHADER IS NOT CREATED ***" << std::endl;
        return;
    }

    glAttachShader(id, shader.get_id());
}

bool ShaderProgram::link_program() const  {
    if(id == 0) {
        std::cerr << "*** PROGRMA IS NOT CREATED ***" << std::endl;
        return false;
    }

    glLinkProgram(id);

    GLint success;
    GLchar infolog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);

    if (!success) {
        std::cerr << "*** LINK ERROR ***" << std::endl;
        glGetProgramInfoLog(id, 512, NULL, infolog);
        std::cerr << infolog << std::endl;
        return false;
    }
    
    return true;
}

void ShaderProgram::use() const {
    if(id == 0) {
        std::cerr << "*** PROGRMA IS NOT CREATED ***" << std::endl;
        return;
    }

    glUseProgram(id);
}


