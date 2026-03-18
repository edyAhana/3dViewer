#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <filesystem>
#include <optional>

#include "GLFW.hpp"

using Path = std::filesystem::path;

class Shader {
private:
    std::string shader; 
    GLuint id;

    void check_error(const char* msg) const;
public:
    Shader();
    Shader(std::string shader);
    Shader(const Shader& other) = delete;
    Shader& operator=(const Shader& other) = delete;
    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;
    ~Shader();

    static std::optional<Shader> read_from_file(const Path& file_path);

    void set_shader(std::string sh);
    void load_shader(GLenum type);
    bool compile_shader() const ;

    GLuint get_id() const;
};

#endif
