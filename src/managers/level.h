#pragma once

#include <entityx/entityx.h>

#include <entities/usership.h>

class Level : public entityx::Manager {
    public:
        Level(int width, int height) :
            width(width), height(height),
            user_ship(width/2, height/2) {}

        void send_up();
        void send_down();
        void send_left();
        void send_right();
        void send_space();

    protected:
        void configure();

        void initialize();

        void update(double dt);

    private:
        int width, height;
        UserShip user_ship;
};

