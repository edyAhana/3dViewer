#include <iostream>
#include <fstream>
#include <sstream>
#include <optional>

#include "Shader.hpp"
#include "GLFW.hpp"


Shader::Shader(): shader(), id(0) {} 

Shader::Shader(std::string shader): shader(std::move(shader))
                                  , id(0) {}
                                  
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
        std::cerr << "*** NO SUCH FILE OR DIRECTORY TO READ SHADER ***" << std::endl;
        return std::nullopt;
    }

    if(!std::filesystem::is_regular_file(file_path)) {
        std::cerr << "*** NO SOURCE FILE WITH SHADER ***" << std::endl;
        return std::nullopt;
    }

    std::ifstream is(file_path);

    if(!is.is_open()) {
        std::cerr << "*** FAILED TO OPEN FILE ***" << std::endl;
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
        std::cerr << "*** SHADER IS NOT CREATED ***" << std::endl;
        return false;
    }

    glCompileShader(id);

    GLint success;
    GLchar infolog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(!success) {
        std::cerr << "*** COMPILE ERROR ***" << std::endl;
        glGetShaderInfoLog(id, 512, NULL, infolog);
        std::cerr << infolog << std::endl;
        return false;
    }
    return true;
}

GLuint Shader::get_id() const {
    return id;
}
