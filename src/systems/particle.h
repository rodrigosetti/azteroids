#pragma once

#include <entityx/entityx.h>

class ParticleSystem : public entityx::System<ParticleSystem> {
    public:
        void update(entityx::ptr<entityx::EntityManager> entities,
                    entityx::ptr<entityx::EventManager> events,
                    double dt) override;
};

