#include <GL/glut.h>
#include "ship.h"

void Ship::render() {
    const GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    const GLfloat mat_shininess[] = { 100.0 };

    const GLfloat mat_diffuse_1[] = {1.f, 0.f, 0.f};
    const GLfloat mat_diffuse_2[] = {0.f, 1.f, 0.f};
    const GLfloat mat_diffuse_3[] = {0.f, 0.f, 1.f};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glPushMatrix();
    glScalef(30, 30, 30);

    glBegin(GL_TRIANGLES);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_1);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.f, 0.6f, -0.5f);

    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_2);
    glVertex3f(0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.f, 0.6f, -0.5f);

    glMaterialfv(GL_FRONT, GL_EMISSION, mat_diffuse_3);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glVertex3f(0.f, -0.2f, -0.5f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glEnd();
    glPopMatrix();
}

