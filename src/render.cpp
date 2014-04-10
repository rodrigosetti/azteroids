#include <OpenGL/gl.h>
#include "render.h"

void RenderSystem::update(entityx::ptr<entityx::EntityManager> es,
                          entityx::ptr<entityx::EventManager> events,
                          double dt) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, -1.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, -1.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, -1.f);
    glEnd();
};

