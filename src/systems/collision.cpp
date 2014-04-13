#include <components/geometry.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>

#include "collision.h"

void CollisionSystem::update(entityx::ptr<entityx::EntityManager> entities,
                             entityx::ptr<entityx::EventManager> events,
                             double dt) {

    for (auto entity1 : entities->entities_with_components<Position, Geometry>()) {
        entityx::ptr<Position> pos1 = entity1.component<Position>();
        entityx::ptr<Geometry> geo1 = entity1.component<Geometry>();
        entityx::ptr<Momentum> mom1 = entity1.component<Momentum>();

        for (auto entity2 : entities->entities_with_components<Position, Geometry>()) {
            if (entity1 != entity2) {
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
        }
    }
}

