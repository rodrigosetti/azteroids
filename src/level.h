#pragma once

#include <entityx/entityx.h>

class Level : public entityx::Manager {
    protected:
        void configure();

        void initialize();

        void update(double dt);
};

