#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Math.hpp"

struct Light {
    vector3 position;
    vector3 color;

    Light(const vector3& position, const vector3& color)
        : position(position), color(color) {}
};


#endif // LIGHT_HPP