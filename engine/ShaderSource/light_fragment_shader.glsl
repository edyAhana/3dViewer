#version 410 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
}; 

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 out_norm;
in vec3 fragmet_pos;

out vec4 color;

uniform vec3 our_color;
uniform vec3 light_pos;
uniform vec3 view_pos;
uniform Material material;
uniform Light light; 

void main()
{
    vec3 ambient_light = light.ambient * material.ambient;
    
    vec3 norm = normalize(out_norm);
    vec3 light_dir = normalize(light.position - fragmet_pos);

    float diff = abs(dot(norm, light_dir));
    vec3 diffuse = (material.diffuse * diff) * light.diffuse;

    vec3 view_dir = normalize(view_pos - fragmet_pos);
    vec3 reflect_dir = reflect(-light_dir, norm);

    float spec = pow(max(dot(view_dir, reflect_dir), 0.0), material.shininess);
    vec3 specular = (material.specular * spec) * light.specular;

    vec3 result_color = (ambient_light + diffuse + specular) * our_color;
    color = vec4(result_color, 1.0);
}
