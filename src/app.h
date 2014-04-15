#pragma once

#include <managers/level.h>

class App {

    public:

        App(int width, int height);

        void initialize();

        void step(double dt);

        void send_up();
        void send_down();
        void send_left();
        void send_right();
        void send_space();

    private:

        int width, height;
        Level level;
};

