#pragma once

#include <entityx/entityx.h>

struct Momentum : entityx::Component<Momentum> {
    Momentum(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    float x, y;
};

