#ifndef GLFW_INITIALIZER_HPP
#define GLFW_INITIALIZER_HPP

#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GLFWInitializer {
public:
    GLFWInitializer() = default;
    ~GLFWInitializer() {
        glfwTerminate();
    }

    bool init() const { 
        if(!glfwInit()) {
            return false;
        }

        return true;
    }
};


#endif
