#pragma once

#include <entityx/entityx.h>

struct Appearance : entityx::Component<Appearance> {

    virtual void render(float dt) {}
    virtual void render(entityx::Entity entity, float dt) { render(dt); }
};

