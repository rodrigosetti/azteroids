#pragma once

#include <entityx/entityx.h>

struct Attrition : entityx::Component<Attrition> {
    Attrition(float e = 0.0f) : e(e) {}

    float e;
};

