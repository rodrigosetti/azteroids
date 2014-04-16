#include <components/appearance/asteroid.h>
#include <components/appearance/particle.h>
#include <components/geometry.h>
#include <components/identity.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>
#include <components/particle.h>

#include "collision.h"

const float MINIMUM_MASS = 10;

void handle_cases(entityx::ptr<entityx::EntityManager> entity_manager,
                  entityx::Entity entity1, entityx::Entity entity2);
void bounce(entityx::Entity entity1, entityx::Entity entity2);

void CollisionSystem::update(entityx::ptr<entityx::EntityManager> entities,
                             entityx::ptr<entityx::EventManager> events,
                             double dt) {
    for (auto entity1 : entities->entities_with_components<Position, Geometry>()) {
        entityx::ptr<Position> pos1 = entity1.component<Position>();
        entityx::ptr<Geometry> geo1 = entity1.component<Geometry>();

        for (auto entity2 : entities->entities_with_components<Position, Geometry>()) {
            if (entity1.valid() && entity2.valid() && entity1 != entity2) {
                entityx::ptr<Position> pos2 = entity2.component<Position>();
                entityx::ptr<Geometry> geo2 = entity2.component<Geometry>();

                double distance = pos1->distance(pos2);
                double min_distance = geo1->radius + geo2->radius;

                if (distance < min_distance) {
                    // Collision!
                    handle_cases(entities, entity1, entity2);
                }
            }
        }
    }
}

void handle_cases(entityx::ptr<entityx::EntityManager> entity_manager,
                  entityx::Entity entity1, entityx::Entity entity2) {
    const float spark_color[] = {0.5f, 1.0f, 1.0f};

    entityx::ptr<Identity> id1 = entity1.component<Identity>();
    entityx::ptr<Identity> id2 = entity2.component<Identity>();

    // handle cases...
    if (id1->identity == EntityIdentity::ASTEROID &&
        id2->identity == EntityIdentity::ASTEROID) {
        bounce(entity1, entity2);

    } else if (id1->identity == EntityIdentity::LASER &&
               id2->identity == EntityIdentity::ASTEROID) {
        entityx::ptr<Mass>     mass     = entity2.component<Mass>();
        entityx::ptr<Position> position = entity2.component<Position>();

        entity1.destroy();
        entity2.destroy();

        if (mass->mass > MINIMUM_MASS * 2) {
            int parts = fmin(4, mass->mass / MINIMUM_MASS);
            float new_mass = mass->mass * 1.5 / parts;
            for (int i = 0; i < parts; i++) {
                entityx::Entity asteroid = entity_manager->create();
                asteroid.assign<Asteroid>(new_mass);
                asteroid.assign<Identity>(EntityIdentity::ASTEROID);
                asteroid.assign<Mass>(new_mass);
                asteroid.assign<Geometry>(new_mass);
                asteroid.assign<Momentum>(rand() % 1000 - 500, rand() % 1000 - 500,
                                          rand() % 1200 - 600);
                asteroid.assign<Position>(position->x + (rand() % int(new_mass)) - new_mass/2,
                                          position->y + (rand() % int(new_mass)) - new_mass/2,
                                          rand() % 360,
                                          rand() % 10, rand() % 10, rand() % 10);
            }
        }

        // Create some particle
        for (int i = 0; i < 500; i++) {
            float angle = rand() % 360;
            float speed = rand() % 100 + 50;
            float duration = (rand() % 1000) / 1000.0f;
            entityx::Entity spark = entity_manager->create();
            spark.assign<Spark>(spark_color);
            spark.assign<Particle>(duration);
            spark.assign<Identity>(EntityIdentity::PARTICLE);
            spark.assign<Momentum>(cos(angle) * speed, sin(angle) * speed);
            spark.assign<Position>(position->x, position->y,
                                   0, 0, 0, 1, 
                                   OffLimitBehavior::DESTROY);
        }
        entityx::Entity cloud = entity_manager->create();
        cloud.assign<Cloud>(spark_color, 500);
        cloud.assign<Particle>(0.2f);
        cloud.assign<Identity>(EntityIdentity::PARTICLE);
        cloud.assign<Position>(position->x, position->y);

    } else if (id2->identity == EntityIdentity::LASER &&
               id1->identity == EntityIdentity::ASTEROID) {
        // just swap...
        handle_cases(entity_manager, entity2, entity1);
    }
}

void bounce(entityx::Entity entity1, entityx::Entity entity2) {
    entityx::ptr<Position> pos1 = entity1.component<Position>();
    entityx::ptr<Geometry> geo1 = entity1.component<Geometry>();
    entityx::ptr<Momentum> mom1 = entity1.component<Momentum>();

    entityx::ptr<Position> pos2 = entity2.component<Position>();
    entityx::ptr<Geometry> geo2 = entity2.component<Geometry>();

    double distance = pos1->distance(pos2);
    double min_distance = geo1->radius + geo2->radius;

    if (distance < min_distance) {
        // Collision!
        double dx = (pos2->x - pos1->x) / distance;
        double dy = (pos2->y - pos1->y) / distance;
        double adjust = (min_distance - distance) / 2.0;

        // correct position to the minimum distance
        pos1->x -= dx * adjust;
        pos1->y -= dy * adjust;
        pos2->x += dx * adjust;
        pos2->y += dy * adjust;

        entityx::ptr<Momentum> mom2 = entity2.component<Momentum>();

        if (mom1 && mom2) {
            // Exchange momentum
            double contrib1 = (mom1->x * dx) + (mom1->y * dy);
            double contrib2 = (mom2->x * dx) + (mom2->y * dy);

            mom1->x += contrib2 * dx;
            mom1->y += contrib2 * dy;
            mom1->x -= contrib1 * dx;
            mom1->y -= contrib1 * dy;

            mom2->x += contrib1 * dx;
            mom2->y += contrib1 * dy;
            mom2->x -= contrib2 * dx;
            mom2->y -= contrib2 * dy;
        }
    }
}

