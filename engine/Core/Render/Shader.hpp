#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <filesystem>

using Path = std::filesystem::path;

class Shader {
private:
    std::string shader; 
    GLuint id;
public:
    Shader();
    Shader(std::string shader);
    Shader(const Shader& other) = default;
    Shader& operator=(const Shader& other) = default;
    ~Shader();

    static std::optional<Shader> read_from_file(const Path& file_path);

    void set_shader(std::string sh);
    void load_shader(GLenum type);
    bool compile_shader() const ;

    GLuint get_id() const;
};

#endif
