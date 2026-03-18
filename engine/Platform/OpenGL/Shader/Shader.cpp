#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>

#include "Shader.hpp"
#include "GLFW.hpp"


Shader::Shader(): shader(), id(0) {} 

Shader::Shader(std::string shader): shader(std::move(shader))
                                  , id(0) {}
                                  
Shader::Shader(Shader&& other) noexcept : shader(std::move(other.shader))
                                        , id(other.id) {
    other.id = 0;
}

Shader& Shader::operator=(Shader&& other) noexcept {
    if(this != &other) {
        shader = std::move(other.shader);
        id = other.id;
        other.id = 0;
    }
    return *this;
}   

Shader::~Shader() {
    if(id != 0) {
        glDeleteShader(id);
    }
}

void Shader::set_shader(std::string sh) {
    shader = std::move(sh);
}

std::optional<Shader> Shader::read_from_file(const Path& file_path) {
    if(!std::filesystem::exists(file_path)) {
        std::cerr << "[Shader::read_from_file] : no such file or directory to read shader" << std::endl;
        return std::nullopt;
    }

    if(!std::filesystem::is_regular_file(file_path)) {
        std::cerr << "[Shader::read_from_file] : file is not a regular file" << std::endl;
        return std::nullopt;
    }

    std::ifstream is(file_path);

    if(!is.is_open()) {
        std::cerr << "[Shader::read_from_file] : failed to open file" << std::endl;
        return std::nullopt;
    }

    std::stringstream os;
    std::string line;

    while(std::getline(is, line)) {
        os << line << std::endl;
    }

    return Shader(os.str());
}

void Shader::load_shader(GLenum type) {
    if(id) {
        return;
    }
    
    id = glCreateShader(type);
    auto str = shader.c_str();
    glShaderSource(id, 1, &str, NULL);
}

bool Shader::compile_shader() const {
    if(id == 0) {
        std::cerr << "[Shader::compile_shader] : Shader is not created." << std::endl;
        return false;
    }

    glCompileShader(id);

    GLint success;
    GLchar infolog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    check_error("compile_shader");
    return true;
}

GLuint Shader::get_id() const {
    return id;
}

void Shader::check_error(const char* msg) const {
    GLint success;
    GLchar infolog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(!success) {
        std::cerr << "[Shader::check_error] : [" << msg << "]" << std::endl;
        glGetShaderInfoLog(id, 512, NULL, infolog);
        std::cerr << infolog << std::endl;
    }
}