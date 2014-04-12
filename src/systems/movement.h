#pragma once

#include <entityx/entityx.h>

class MovementSystem : public entityx::System<MovementSystem> {
    public:
        void update(entityx::ptr<entityx::EntityManager> entities,
                    entityx::ptr<entityx::EventManager> events,
                    double dt) override;
};

