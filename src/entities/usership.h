#pragma once

#include <entityx/entityx.h>

class UserShip {

    public:
        UserShip(float x, float y) : x(x), y(y) {}

        void initialize(entityx::ptr<entityx::EntityManager> entities,
                        entityx::ptr<entityx::EventManager> events);

        void update(double dt);

        void move_forward(double dt);
        void move_backwards(double dt);
        void rotate_left(double dt);
        void rotate_right(double dt);
        void fire(double dt);

    private:
        float x, y;
        double cool_down = 0;

        entityx::Entity entity;
        entityx::ptr<entityx::EntityManager> entity_manager;

        void change_linear_momentum(float delta);
        void change_angular_momemtum(float delta);
};

