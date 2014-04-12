#pragma once

#include <entityx/entityx.h>

class Level : public entityx::Manager {
    public:
        Level(int width, int height) : width(width), height(height) {}

    protected:
        void configure();

        void initialize();

        void update(double dt);

    private:

        int width;
        int height;
};

