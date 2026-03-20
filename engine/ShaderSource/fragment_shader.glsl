#version 410 core

out vec4 color;

uniform vec3 our_color;

void main()
{
    color = vec4(our_color, 1.0);
}
