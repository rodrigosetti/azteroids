#pragma once

#include <managers/level.h>

struct Keys {
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
    bool space = false;
};

class App {

    public:

        App(int width, int height);

        void initialize();

        void step(double dt);

        Keys keys_pressed;

        int width, height;

    private:

        Level level;
};

