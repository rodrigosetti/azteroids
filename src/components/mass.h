#pragma once

#include <entityx/entityx.h>

struct Mass : entityx::Component<Mass> {
    Mass(float mass = 0.0f) : mass(mass) {}

    float mass;
};

