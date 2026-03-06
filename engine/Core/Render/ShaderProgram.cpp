#include "ShaderProgram.hpp"
#include "GLFWInitializer.hpp"

ShaderProgrma(): id(0) {}
~ShaderPogram() {}

void init() {
    id = glCreateProgram();
}

void attach_shader(const Shader& shader) const {
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

bool link_progrma() const  {
    if(id == 0) {
        std::cerr << "*** PROGRMA IS NOT CREATED ***" << std::endl;
        return false;
    }

    glLinkProgram(id);

    GLint success;
    GLchar infolog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success) {
        std::cerr << "*** LINK ERROR ***" << std::endl;
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cerr << infolog << std::endl;
        return false;
    }
    
    return true;
}

void use() const {
    if(id == 0) {
        std::cerr << "*** PROGRMA IS NOT CREATED ***" << std::endl;
        return;
    }

    glUseProgram(id);
}


