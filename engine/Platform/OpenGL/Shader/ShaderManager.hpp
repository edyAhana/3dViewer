#ifndef MAIN_SHADERMANAGER_HPP
#define MAIN_SHADERMANAGER_HPP

#include <memory>
#include <filesystem>
#include "unordered_map"

#include "Shader.hpp"
#include "ShaderProgram.hpp"

using Path = std::filesystem::path;

class ShaderManager {
private:
    static ShaderProgram program;
    static std::unordered_map<std::string, std::shared_ptr<Shader>> shaders;
    static std::unordered_map<std::string, std::shared_ptr<ShaderProgram>> programs;
public:
    static bool init( const Path& vertex_shader_path
             , const Path& fragment_shader_path);

    static void use_program();

    static unsigned get_program_id();

    static std::shared_ptr<Shader> add_shader(const std::string& name, const Path& shader_path, GLenum type);   
    static std::shared_ptr<ShaderProgram> add_program(std::vector<std::string> shader_names, const std::string& program_name);
    static std::shared_ptr<Shader> get_shader(const std::string& name);
    static std::shared_ptr<ShaderProgram> get_program(const std::string& name);
};


#endif //MAIN_SHADERMANAGER_HPP