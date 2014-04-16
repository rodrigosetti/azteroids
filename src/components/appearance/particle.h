#pragma once

#include "appearance.h"

class Spark : public Appearance {
    public:
        Spark(const float color[]) : color(color) {};

        void render(entityx::Entity entity, float dt);

    private:
        const float *color;
};

class Cloud : public Appearance {
    public:
        Cloud(const float color[], const float grow_speed) :
              color(color), grow_speed(grow_speed) {}

        void render(entityx::Entity entity, float dt);

    private:
        const float *color;
        const float grow_speed;
};

