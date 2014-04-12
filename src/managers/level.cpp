#include "level.h"
#include <systems/render.h>
#include <components/position.h>
#include <components/momentum.h>
#include <components/mass.h>
#include <components/appearance/asteroid.h>

#define AZTEROIDS_NUM 10

void Level::configure() {
    system_manager->add<RenderSystem>();
};

void Level::initialize() {
    for (int i = 0; i < AZTEROIDS_NUM; i++) {
        entityx::Entity entity = entity_manager->create();
        entity.assign<Position>(rand() % width, rand() % height);
        entity.assign<Momentum>(rand() % 10 - 5, rand() % 10 - 5);
        entity.assign<Mass>(rand() % 100 + 10);
        entity.assign<Azteroid>();
    }
}

void Level::update(double dt) {
    system_manager->update<RenderSystem>(dt);
}

