#ifndef MAIN_SHADERPROGRAM_HPP
#define MAIN_SHADERPROGRAM_HPP

#include  "Shader.hpp"
#include "GLFW.hpp"

class ShaderProgram {
private:
    GLuint id;
public:
    ShaderProgram();
    ~ShaderProgram();

    void init();
    void attach_shader(const Shader& shader) const;
    bool link_program() const;
    void use() const;
};

#endif 
