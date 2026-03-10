#include "../Math.hpp"
#include "Camera.hpp"

#include <ios>

Camera::Camera( const vector3& position
                , const vector3& target)
                  : position(position)
                  , target(target) {
    set_up();
}

void Camera::set_up() {
    front = glm::normalize(position - target);
    vector3 world_up(0.0f, 1.0f, 0.0f);

    right = glm::normalize(glm::cross(world_up, front));
    up = glm::normalize(glm::cross(front, right));
}

float Camera::get_fov() const {
    return fov;
}

matrix4 Camera::get_view() const {
    return glm::lookAt(position, target, vector3(0.0f, 1.0f, 0.0f));
}

void Camera::move_forward(float distance) {
    position = position - front * distance;
    target = target - front * distance;
    set_up();
}

void Camera::move_backward(float distance) {
    position = position + front * distance;
    target = target + front * distance;
    set_up();
}

void Camera::move_left(float distance) {
    position = position - right * distance;
    target = target - right * distance;
    set_up();
}
void Camera::move_right(float distance) {
    position = position + right * distance;
    target = target + right * distance;
    set_up();
}

void Camera::move_up(float distance) {
    position = position + up * distance;
    target = target + up * distance;
    set_up();
}

void Camera::move_down(float distance) {
    position = position - up * distance;
    target = target - up * distance;
    set_up();
}

void Camera::rotate(float delta_yaw, float delta_pitch) {
    auto modulo = glm::length(target - position);

    yaw += delta_yaw;
    pitch -= delta_pitch;

    pitch = glm::clamp(pitch, -89.0f, 89.0f);

    front.x = glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
    front.y = glm::sin(glm::radians(pitch));
    front.z = glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
    front = glm::normalize(front);
    //
    target = position + front * modulo;
    set_up();
}
