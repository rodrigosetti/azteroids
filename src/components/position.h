#pragma once

#include <entityx/entityx.h>

struct Position : entityx::Component<Position> {
    Position(float x = 0.0f, float y = 0.0f,
             float rotation = 0.0f,
             float rotation_axis_x = 0.0f,
             float rotation_axis_y = 0.0f,
             float rotation_axis_z = 1.0f) :
            x(x), y(y), rotation(rotation),
            rotation_axis_x(rotation_axis_x),
            rotation_axis_y(rotation_axis_y),
            rotation_axis_z(rotation_axis_z) {}

    float x, y, rotation, rotation_axis_x, rotation_axis_y, rotation_axis_z;
};

