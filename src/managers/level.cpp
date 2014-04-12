#include <components/appearance/asteroid.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>
#include <systems/collision.h>
#include <systems/movement.h>
#include <systems/render.h>

#include "level.h"

const int AZTEROIDS_NUM = 10;

void Level::configure() {
    system_manager->add<CollisionSystem>();
    system_manager->add<MovementSystem>(width, height);
    system_manager->add<RenderSystem>();
};

void Level::initialize() {
    for (int i = 0; i < AZTEROIDS_NUM; i++) {
        float mass = rand() % 100 + 10;
        entityx::Entity entity = entity_manager->create();
        entity.assign<Asteroid>(mass);
        entity.assign<Mass>(mass);
        entity.assign<Momentum>(rand() % 1000 - 500, rand() % 1000 - 500);
        entity.assign<Position>(rand() % width, rand() % height);
    }
}

void Level::update(double dt) {
    system_manager->update<CollisionSystem>(dt);
    system_manager->update<MovementSystem>(dt);
    system_manager->update<RenderSystem>(dt);
}

