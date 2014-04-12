#include <components/mass.h>
#include <components/position.h>
#include <components/momentum.h>

#include "movement.h"

void MovementSystem::update(entityx::ptr<entityx::EntityManager> entities,
                            entityx::ptr<entityx::EventManager> events,
                            double dt) {
    for (auto entity : entities->entities_with_components<Position, Momentum>()) {
        entityx::ptr<Position> position = entity.component<Position>();
        entityx::ptr<Momentum> momentum = entity.component<Momentum>();
        entityx::ptr<Mass>     mass     = entity.component<Mass>();
        float m = mass? mass->mass : m;

        position->x += momentum->x / m * dt;
        position->y += momentum->y / m * dt;

        while (position->x < 0) {
            position->x += width;
        }
        while (position->x > width) {
            position->x -= width;
        }
        while (position->y < 0) {
            position->y += height;
        }
        while (position->y > height) {
            position->y -= height;
        }
    }
}

