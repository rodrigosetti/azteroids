#include <app.h>
#include <components/appearance/asteroid.h>
#include <components/geometry.h>
#include <components/identity.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>
#include <systems/collision.h>
#include <systems/movement.h>
#include <systems/render.h>
#include <systems/particle.h>

#include "level.h"

const int AZTEROIDS_NUM = 20;

Level::Level(App *application) : application(application),
                                 user_ship(application->width/2,
                                           application->height/2) {}

void Level::configure() {
    system_manager->add<CollisionSystem>();
    system_manager->add<MovementSystem>(application->width,
                                        application->height);
    system_manager->add<RenderSystem>();
    system_manager->add<ParticleSystem>();
};

void Level::initialize() {

    // Create asteroids:
    for (int i = 0; i < AZTEROIDS_NUM; i++) {
        float mass = rand() % 20 + 20;
        entityx::Entity asteroid = entity_manager->create();
        asteroid.assign<Asteroid>(mass);
        asteroid.assign<Identity>(EntityIdentity::ASTEROID);
        asteroid.assign<Mass>(mass);
        asteroid.assign<Geometry>(mass);
        asteroid.assign<Momentum>(rand() % 1000 - 500, rand() % 1000 - 500,
                                  rand() % 1200 - 600);
        asteroid.assign<Position>(rand() % application->width,
                                  rand() % application->height,
                                  rand() % 360,
                                  rand() % 10, rand() % 10, rand() % 10);
    }

    // Initialize user-controllable ship:
    user_ship.initialize(entity_manager, event_manager);
}

void Level::update(double dt) {
    system_manager->update<CollisionSystem>(dt);
    system_manager->update<MovementSystem>(dt);
    system_manager->update<ParticleSystem>(dt);
    system_manager->update<RenderSystem>(dt);

    user_ship.update(dt);

    // update user ship based on the keys state
    if (application->keys_pressed.up) {
        user_ship.move_forward(dt);
    }
    if (application->keys_pressed.down) {
        user_ship.move_backwards(dt);
    }
    if (application->keys_pressed.left) {
        user_ship.rotate_left(dt);
    }
    if (application->keys_pressed.right) {
        user_ship.rotate_right(dt);
    }
    if (application->keys_pressed.space) {
        user_ship.fire(dt);
    }
}

