#ifndef MAIN_CAMERA_HPP
#define MAIN_CAMERA_HPP

#include "Math.hpp"

class Camera {
private:
    vector3 position;
    vector3 front;
    vector3 up;
    vector3 right;
    vector3 target;
    float fov = 45.0f;
    float yaw = -89.0f, pitch = 1.0f;

    void set_up();
public:
    Camera( const vector3& position = vector3(0.0f, 0.0f, 3.0f)
          , const vector3& target = vector3(0.0f, 0.0f, 0.0f));

    void move_forward(float distance);
    void move_backward(float distance);
    void move_left(float distance);
    void move_right(float distance);
    void move_up(float distance);
    void move_down(float distance);

    void rotate(float delta_yaw, float delta_pitch);

    float get_fov() const;

    matrix4 get_view() const;
    vector3 get_position() const {
        return position;
    }
};


#endif //MAIN_CAMERA_HPP