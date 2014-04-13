#pragma once

#include <entityx/entityx.h>

struct Attrition : entityx::Component<Attrition> {
    Attrition(float linear = 1.0f, float angular = 1.0f) :
             linear(linear), angular(angular) {}

    float linear, angular;
};

