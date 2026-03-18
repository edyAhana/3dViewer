#include <iostream>

#include "ShaderManager.hpp"
#include "Shader.hpp"

ShaderProgram ShaderManager::program{};
std::unordered_map<std::string, std::shared_ptr<Shader>> ShaderManager::shaders{};
std::unordered_map<std::string, std::shared_ptr<ShaderProgram>> ShaderManager::programs{};

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

std::shared_ptr<Shader> ShaderManager::add_shader(const std::string& name, const Path& shader_path, GLenum type) {
    auto shader = Shader::read_from_file(shader_path);
    if(!shader) {
        std::cerr << "Failed to load shader." << std::endl;
        return nullptr;
    }

    shader->load_shader(type);
    if(!shader->compile_shader()) {
        std::cerr << "[ShaderManager::add_shader] : Failed to compile shader." << std::endl;
        return nullptr;
    }

    auto ptr = std::make_shared<Shader>(std::move(shader.value()));
    shaders[name] = ptr;
    return ptr;
}

std::shared_ptr<ShaderProgram> ShaderManager::add_program(std::vector<std::string> shader_names, const std::string& program_name) {
    auto program = std::make_shared<ShaderProgram>();
    program->init();

    for(const auto& name : shader_names) {
        auto shader = get_shader(name);
        if(!shader) {
            std::cerr << "[ShaderManager::add_program] : Failed to get shader with name " << name << std::endl;
            return nullptr;
        }
        program->attach_shader(*shader);
    }

    if(!program->link_program()) {
        std::cerr << "[ShaderManager::add_program] : Failed to link program." << std::endl;
        return nullptr;
    }

    programs[program_name] = program;
    return program;
}


std::shared_ptr<Shader> ShaderManager::get_shader(const std::string& name) {
    if(!shaders.contains(name)) {
        std::cerr << "[ShaderManager::get_shader] : No shader with name " << name << std::endl;
        return nullptr;
    }
    return shaders[name];
}

std::shared_ptr<ShaderProgram> ShaderManager::get_program(const std::string& name) {
    if(!programs.contains(name)) {
        std::cerr << "[ShaderManager::get_program] : No program with name " << name << std::endl;
        return nullptr;
    }
    return programs[name];
}