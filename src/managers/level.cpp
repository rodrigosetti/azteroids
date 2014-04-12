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
    system_manager->add<MovementSystem>();
    system_manager->add<RenderSystem>();
};

void Level::initialize() {
    for (int i = 0; i < AZTEROIDS_NUM; i++) {
        entityx::Entity entity = entity_manager->create();
        entity.assign<Asteroid>();
        entity.assign<Mass>(rand() % 100 + 10);
        entity.assign<Momentum>(rand() % 10 - 5, rand() % 10 - 5);
        entity.assign<Position>(rand() % width, rand() % height);
    }
}

void Level::update(double dt) {
    system_manager->update<CollisionSystem>(dt);
    system_manager->update<MovementSystem>(dt);
    system_manager->update<RenderSystem>(dt);
}

