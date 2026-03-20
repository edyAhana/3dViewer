#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Math.hpp"
#include "ShaderProgram.hpp"

class Material {
private:
    vector3 color;
    std::shared_ptr<ShaderProgram> shader_program;
public:
    Material() = default;
    Material(const vector3& color) : color(color) {}
    ~Material() = default;

    auto get_color() const noexcept { return color; }
    void set_color(const vector3& new_color) noexcept { color = new_color; } 
    auto get_shader_program() const noexcept { return shader_program; }
    void set_shader_program(std::shared_ptr<ShaderProgram> new_shader_program) noexcept { shader_program = std::move(new_shader_program); }
};



#endif 