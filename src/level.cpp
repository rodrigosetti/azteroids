#include "level.h"
#include "render.h"
// #include "movement.h"
// #include "collision.h"

void Level::configure() {
    system_manager->add<RenderSystem>();
    /*
    system_manager->add<MovementSystem>();
    system_manager->add<CollisionSystem>();
    */
};

void Level::initialize() {
}

void Level::update(double dt) {
    /*
    system_manager->update<MovementSystem>(dt);
    system_manager->update<CollisionSystem>(dt);
    */
    system_manager->update<RenderSystem>(dt);
}

