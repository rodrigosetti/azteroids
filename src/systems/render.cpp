#include <OpenGL/gl.h>
#include <components/position.h>
#include <components/mass.h>
#include <components/appearance/appearance.h>
#include "render.h"

void RenderSystem::update(entityx::ptr<entityx::EntityManager> entities,
        entityx::ptr<entityx::EventManager> events,
        double dt) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (auto entity : entities->entities_with_components<Position, Mass, Appearance>()) {
        entityx::ptr<Position> position = entity.component<Position>();
        entityx::ptr<Mass> mass = entity.component<Mass>();
        entityx::ptr<Appearance> appearance = entity.component<Appearance>();

        glPushMatrix();
        glTranslatef(position->x, position->y, 1);
        glScalef(mass->mass, mass->mass, 1);
        appearance->render();
        glPopMatrix();
    }
};

