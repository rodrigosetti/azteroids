#pragma once

#include <entityx/entityx.h>

struct Renderable : entityx::Component<Renderable> {
    virtual void render() = 0;
};
