#pragma once

#include "appearance.h"

struct Ship : Appearance {
    void render(float dt);
    void throttle();

    private:

    float throttle_level = 0;
};

