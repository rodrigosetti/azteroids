#include <components/appearance/asteroid.h>
#include <components/geometry.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>
#include <events/useraction.h>
#include <systems/collision.h>
#include <systems/movement.h>
#include <systems/render.h>

#include "level.h"

const int AZTEROIDS_NUM = 20;

void Level::configure() {
    system_manager->add<CollisionSystem>();
    system_manager->add<MovementSystem>(width, height);
    system_manager->add<RenderSystem>();
};

void Level::initialize() {

    // Create asteroids:
    for (int i = 0; i < AZTEROIDS_NUM; i++) {
        float mass = rand() % 20 + 20;
        entityx::Entity entity = entity_manager->create();
        entity.assign<Asteroid>(mass);
        entity.assign<Mass>(mass);
        entity.assign<Geometry>(mass);
        entity.assign<Momentum>(rand() % 1000 - 500, rand() % 1000 - 500,
                                rand() % 1200 - 600);
        entity.assign<Position>(rand() % width, rand() % height,
                                rand() % 360,
                                rand() % 10, rand() % 10, rand() % 10);
    }

    // Initialize user-controllable ship:
    user_ship.initialize(entity_manager, event_manager);
}

void Level::update(double dt) {
    system_manager->update<CollisionSystem>(dt);
    system_manager->update<MovementSystem>(dt);
    system_manager->update<RenderSystem>(dt);
}

void Level::send_up() {
    event_manager->emit<UserAction>(UserActionType::UP);
}

void Level::send_down() {
    event_manager->emit<UserAction>(UserActionType::DOWN);
}

void Level::send_left() {
    event_manager->emit<UserAction>(UserActionType::LEFT);
}

void Level::send_right() {
    event_manager->emit<UserAction>(UserActionType::RIGHT);
}

