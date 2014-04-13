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

        for (auto entity2 : entities->entities_with_components<Position, Geometry>()) {
            if (entity1 != entity2) {
                entityx::ptr<Position> pos2 = entity2.component<Position>();
                entityx::ptr<Geometry> geo2 = entity2.component<Geometry>();

                double distance = pos1->distance(pos2);
                double min_distance = geo1->radius + geo2->radius;

                if (distance < min_distance) {
                    // Collision!
                    double dx = pos2->x - pos1->x;
                    double dy = pos2->y - pos1->y;
                    double adjust = (min_distance - distance) / 2.0;

                    // correct position to the minimum distance
                    pos1->x -= dx / distance * adjust;
                    pos1->y -= dy / distance * adjust;
                    pos2->x += dx / distance * adjust;
                    pos2->y += dy / distance * adjust;
                }
            }
        }
    }
}

