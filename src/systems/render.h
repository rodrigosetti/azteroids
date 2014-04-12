#pragma once

#include <entityx/entityx.h>

class RenderSystem : public entityx::System<RenderSystem> {
    public:
        void update(entityx::ptr<entityx::EntityManager> es,
                    entityx::ptr<entityx::EventManager> events,
                    double dt) override;

        int width;
        int height;
};

