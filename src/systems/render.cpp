#include <OpenGL/gl.h>
#include <components/position.h>
#include <components/mass.h>
#include <components/renderable.h>
#include "render.h"

void RenderSystem::update(entityx::ptr<entityx::EntityManager> entities,
        entityx::ptr<entityx::EventManager> events,
        double dt) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (auto entity : entities->entities_with_components<Position, Mass, Renderable>()) {
        entityx::ptr<Position> position = entity.component<Position>();
        entityx::ptr<Mass> mass = entity.component<Mass>();
        entityx::ptr<Renderable> renderable = entity.component<Renderable>();

        glPushMatrix();
        glTranslatef(position->x, position->y, 1);
        glScalef(mass->mass, mass->mass, 1);
        renderable->render();
        glPopMatrix();
    }
};

