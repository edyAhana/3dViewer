#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "GLFWInitializer.hpp"

class Renderer {
public: 
    static void init();
        
    static void set_clear_color(float r = 255.0f, float g = 255.0f, float b = 255.0f, float a = 255.0f);
    static void clear();
};


#endif

