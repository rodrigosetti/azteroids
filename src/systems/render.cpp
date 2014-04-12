#include <OpenGL/gl.h>

#include <components/appearance/appearance.h>
#include <components/mass.h>
#include <components/position.h>

#include "render.h"

void RenderSystem::update(entityx::ptr<entityx::EntityManager> entities,
                          entityx::ptr<entityx::EventManager> events,
                          double dt) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (auto entity : entities->entities_with_components<Appearance>()) {
        entityx::ptr<Position> position     = entity.component<Position>();
        entityx::ptr<Appearance> appearance = entity.component<Appearance>();

        glPushMatrix();
        if (position) {
            glTranslatef(position->x, position->y, 1);
        }
        appearance->render();
        glPopMatrix();
    }
};

