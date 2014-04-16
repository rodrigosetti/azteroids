#pragma once

#include <entityx/entityx.h>

struct Particle : entityx::Component<Particle> {
    Particle(float duration = 1.0f) : duration(duration) {}

    float age = 0;
    float duration;
};

