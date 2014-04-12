#pragma once

#include <entityx/entityx.h>

class CollisionSystem : public entityx::System<CollisionSystem> {
    public:
        void update(entityx::ptr<entityx::EntityManager> entities,
                    entityx::ptr<entityx::EventManager> events,
                    double dt) override;
};

struct Collision : public entityx::Event<Collision> {
    Collision(entityx::Entity left, entityx::Entity right) : left(left), right(right) {}

    entityx::Entity left, right;
};

