#include <iostream>

#include "ShaderManager.hpp"

ShaderProgram ShaderManager::program{};

bool ShaderManager::init( const Path& vertex_shader_path
         , const Path& fragment_shader_path) {
    auto vsh = Shader::read_from_file(vertex_shader_path);
    auto fsh = Shader::read_from_file(fragment_shader_path);

    if (!vsh || !fsh) {
        std::cerr << "Failed to load shader." << std::endl;
        return false;
    }

    vsh->load_shader(GL_VERTEX_SHADER);
    fsh->load_shader(GL_FRAGMENT_SHADER);
    if (!vsh->compile_shader() || !fsh->compile_shader()) {
        std::cerr << "Failed to compile vertex shader." << std::endl;
        return false;
    }

    program.init();
    program.attach_shader(vsh.value());
    program.attach_shader(fsh.value());
    if (!program.link_program()) {
        std::cerr << "Failed to link program." << std::endl;
        return false;
    }
    return true;
}

void ShaderManager::use_program() {
    program.use();
}

unsigned ShaderManager::get_program_id() {
    return program.get_id();
}
