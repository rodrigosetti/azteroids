#include <OpenGL/gl.h>

#include <components/particle.h>

#include "particle.h"

void ParticleSystem::update(entityx::ptr<entityx::EntityManager> entities,
                          entityx::ptr<entityx::EventManager> events,
                          double dt) {
    for (auto entity : entities->entities_with_components<Particle>()) {
        if (entity.valid()) {
            entityx::ptr<Particle> particle = entity.component<Particle>();

            particle->age += dt;
            if (particle->age > particle->duration) {
                entity.destroy();
            }
        }
    }
};

