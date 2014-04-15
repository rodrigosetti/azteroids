#pragma once

#include <entityx/entityx.h>

enum class OffLimitBehavior { DESTROY, LOOP, BOUNCE };

struct Position : entityx::Component<Position> {
    Position(float x, float y,
             float rotation = 0.0f,
             float rotation_axis_x = 0.0f,
             float rotation_axis_y = 0.0f,
             float rotation_axis_z = 1.0f,
             OffLimitBehavior offLimitBehavior = OffLimitBehavior::LOOP) :
            x(x), y(y), rotation(rotation),
            rotation_axis_x(rotation_axis_x),
            rotation_axis_y(rotation_axis_y),
            rotation_axis_z(rotation_axis_z),
            offLimitBehavior(offLimitBehavior) {}

    float distance(entityx::ptr<Position> other) {
        return sqrt(pow(other->x - x, 2) + pow(other->y - y, 2));
    }

    float x, y,
          rotation,
          rotation_axis_x, rotation_axis_y, rotation_axis_z;
    OffLimitBehavior offLimitBehavior;
};

