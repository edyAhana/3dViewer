#version 410 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 out_norm;
out vec3 fragmet_pos;

void main()
{
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0);
    out_norm = mat3(transpose(inverse(model))) * normal;
    fragmet_pos = vec3(model * vec4(position, 1.0));
}