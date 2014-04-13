#pragma once

#include <managers/level.h>

class App {

    public:

        App(int width, int height);

        void initialize();

        void step(double dt);

    private:

        int width, height;
        Level level;
};

