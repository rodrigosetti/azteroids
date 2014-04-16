#pragma once

#include <entityx/entityx.h>

#include <entities/usership.h>

// foward declaration of App
class App;

class Level : public entityx::Manager {
    public:
        Level(App *application);

    protected:
        void configure();

        void initialize();

        void update(double dt);

    private:
        App *application;
        UserShip user_ship;
};

