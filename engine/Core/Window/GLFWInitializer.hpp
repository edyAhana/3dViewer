#ifndef GLFW_INITIALIZER_HPP
#define GLFW_INITIALIZER_HPP

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFWInitializer {
private:
    bool inited = false;
public:
    GLFWInitializer() {
        if(!glfwInit()) {
            std::cerr << "*** FAILED TO INIT GLFW ***" << std::endl;
            return;
        }

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwTerminate();
            return;
        }
    }

    bool is_init() const noexcept { return inited; }

    ~GLFWInitializer() {
        glfwTerminate();
    }
};


#endif
