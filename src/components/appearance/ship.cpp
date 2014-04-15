#include <OpenGL/gl.h>
#include "ship.h"

void Ship::render(float dt) {
    const GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat mat_shininess[] = { 100.0 };
    const GLfloat mat_diffuse_left[] = {1.f, 0.0f, 0.5f};
    const GLfloat mat_diffuse_right[] = {0.5f, 0.0f, 1.f};

    GLfloat mat_diffuse_throttle[] = {0.5f, throttle_level, throttle_level};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glScalef(30, 30, 30);

    glBegin(GL_TRIANGLES);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_left);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.f, 0.6f, -0.5f);

    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_right);
    glVertex3f(0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.f, 0.6f, -0.5f);

    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_throttle);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glEnd();
    glPopMatrix();

    // decay throttle level
    throttle_level *= pow(0.5f, dt);
}

void Ship::throttle() {
    throttle_level = 1;
}

