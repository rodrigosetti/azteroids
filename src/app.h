#pragma once

#include <managers/level.h>

class App {

    public:

        App(int width, int height);

        void step(double dt);

    private:

        Level level;
};

