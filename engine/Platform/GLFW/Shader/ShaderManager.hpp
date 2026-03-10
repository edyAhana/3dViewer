#ifndef MAIN_SHADERMANAGER_HPP
#define MAIN_SHADERMANAGER_HPP

#include <filesystem>

#include "Shader.hpp"
#include "ShaderProgram.hpp"

using Path = std::filesystem::path;

class ShaderManager {
private:
    static ShaderProgram program;
public:
    static bool init( const Path& vertex_shader_path
             , const Path& fragment_shader_path);

    static void use_program();

    static unsigned get_program_id();
};


#endif //MAIN_SHADERMANAGER_HPP