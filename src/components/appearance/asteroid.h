#pragma once

#include "appearance.h"

class Asteroid : public Appearance {
    public:
        Asteroid(float size) : size(size) {}

        void render();

    private:
        float size;
};

