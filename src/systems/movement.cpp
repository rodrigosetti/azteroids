#include <components/attrition.h>
#include <components/geometry.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>

#include "movement.h"

void MovementSystem::update(entityx::ptr<entityx::EntityManager> entities,
                            entityx::ptr<entityx::EventManager> events,
                            double dt) {
    for (auto entity : entities->entities_with_components<Position, Momentum>()) {
        if (entity.valid()) {
            entityx::ptr<Position> position = entity.component<Position>();
            entityx::ptr<Momentum> momentum = entity.component<Momentum>();
            entityx::ptr<Mass>     mass     = entity.component<Mass>();
            entityx::ptr<Geometry> geometry = entity.component<Geometry>();
            float m = mass? mass->mass : 1;
            float radius = geometry? geometry->radius : 0;

            // linear momentum
            position->x  += momentum->x / m * dt;
            position->y  += momentum->y / m * dt;

            // angular momentum
            position->rotation += momentum->angular / m * dt;

            // Bound rotation to 0-360 deg
            while (position->rotation < 0) { position->rotation += 360; }
            while (position->rotation > 360) { position->rotation -= 360; }

            // Bound linear position
            switch (position->offLimitBehavior) {
                case OffLimitBehavior::DESTROY:
                    if (position->x < -radius        ||
                        position->x > width + radius ||
                        position->y < -radius        ||
                        position->y > height + radius) {
                        entity.destroy();
                    }
                    break;
                case OffLimitBehavior::LOOP:
                    while (position->x < -radius) { position->x += width + radius*2; }
                    while (position->x > width + radius) { position->x -= width + radius*2; }
                    while (position->y < -radius) { position->y += height + radius*2; }
                    while (position->y > height + radius) { position->y -= height + radius*2; }
                    break;
                case OffLimitBehavior::BOUNCE:
                    if (position->x < radius) {
                        position->x = radius;
                        momentum->x *= -1;
                    } else if (position->x > width - radius) {
                        position->x = width - radius;
                        momentum->x *= -1;
                    }
                    if (position->y < radius) {
                        position->y = radius;
                        momentum->y *= -1;
                    } else if (position->y > height - radius) {
                        position->y = height - radius;
                        momentum->y *= -1;
                    }
                    break;
            }
        }
    }

    for (auto entity : entities->entities_with_components<Attrition, Momentum>()) {
        entityx::ptr<Attrition> attrition = entity.component<Attrition>();
        entityx::ptr<Momentum>  momentum  = entity.component<Momentum>();

        momentum->x *= pow(attrition->linear, dt);
        momentum->y *= pow(attrition->linear, dt);
        momentum->angular *= pow(attrition->angular, dt);
    }
}

