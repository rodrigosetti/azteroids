#pragma once

#include <entityx/entityx.h>

struct Appearance : entityx::Component<Appearance> {
    virtual void render(float dt) = 0;
};
