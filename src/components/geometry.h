#pragma once

#include <entityx/entityx.h>

struct Geometry : entityx::Component<Geometry> {
    Geometry(float radius = 0.0f) : radius(radius) {}

    float radius;
};

