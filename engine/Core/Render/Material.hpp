#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Math.hpp"
#include "ShaderProgram.hpp"

class Material {
private:
    vector3 color;
    vector3 ambient_color = vector3(0.2125, 0.1275, 0.054);
    vector3 diffuse_color = vector3(0.714, 0.4284, 0.18144);
    vector3 specular_color = vector3(0.393548, 0.271906, 0.166721);
    float shininess = 0.2f;
    std::shared_ptr<ShaderProgram> shader_program;
public:
    Material() = default;
    Material(const vector3& color, std::shared_ptr<ShaderProgram> shader_program) : color(color), shader_program(std::move(shader_program)) {}
    ~Material() = default;

    auto get_color() const noexcept { return color; }
    void set_color(const vector3& new_color) noexcept { color = new_color; } 
    auto get_shader_program() const noexcept { return shader_program; }
    void set_shader_program(std::shared_ptr<ShaderProgram> new_shader_program) noexcept { shader_program = std::move(new_shader_program); }
};



#endif 