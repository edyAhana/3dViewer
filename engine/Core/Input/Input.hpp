#ifndef INPUT_HPP
#define INPUT_HPP

#include <utility>

#include "Window.hpp"

class Input {
public:
    static bool is_key_pressed(int key);
    static bool is_mouse_pressed(int button);

    static std::pair<double,double> get_cursor_pos();
};



#endif
