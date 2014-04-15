#pragma once

#include <entityx/entityx.h>

#include <events/useraction.h>

class UserShip : public entityx::Receiver<UserShip> {

    public:
        UserShip(float x, float y) : x(x), y(y) {}

        void initialize(entityx::ptr<entityx::EntityManager> entities,
                        entityx::ptr<entityx::EventManager> events);

        void receive(const UserAction &action);

    private:
        float x, y;

        entityx::Entity entity;
        entityx::ptr<entityx::EntityManager> entity_manager;

        void change_linear_momentum(float delta);
        void change_angular_momemtum(float delta);
};

