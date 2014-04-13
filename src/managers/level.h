#pragma once

#include <entityx/entityx.h>

class Level : public entityx::Manager {
    public:
        Level(int width, int height) : width(width), height(height) {}

        void send_up();
        void send_down();
        void send_left();
        void send_right();

    protected:
        void configure();

        void initialize();

        void update(double dt);

    private:
        void change_linear_momentum(float delta);
        void change_angular_momemtum(float delta);

        int width, height;

        entityx::Entity user_ship;
};

