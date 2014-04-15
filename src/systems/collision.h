#pragma once

#include <entityx/entityx.h>

class CollisionSystem : public entityx::System<CollisionSystem> {
    public:
        void update(entityx::ptr<entityx::EntityManager> entities,
                    entityx::ptr<entityx::EventManager> events,
                    double dt) override;
};
