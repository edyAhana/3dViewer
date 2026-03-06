#ifndef MAIN_SHADERPROGRAM_HPP
#define MAIN_SHADERPROGRAM_HPP

inlcude "Shader.hpp"

class ShaderProgram {
private:
    GLuint id;
public:
    ShaderProgrma();
    ~ShaderPogram();

    void init();
    void attach_shader(const Shader& shader) const;
    bool link_progrma() const;
    void use() const;
};

#endif 
