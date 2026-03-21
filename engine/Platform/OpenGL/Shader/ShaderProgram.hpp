#ifndef MAIN_SHADERPROGRAM_HPP
#define MAIN_SHADERPROGRAM_HPP

#include "Math.hpp"
#include "Shader.hpp"
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

    GLuint get_id() const { return id; }
    bool set_uniform_matrix4(const std::string& name, const matrix4& value) const;
    bool set_uniform_vector3(const std::string& name, const vector3& value) const;
    bool set_uniform_float(const std::string& name, float value) const;
};

#endif 
