#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <components/particle.h>

#include "particle.h"

void Spark::render(entityx::Entity entity, float dt) {
    entityx::ptr<Particle> particle = entity.component<Particle>();
    GLfloat fade = particle? 1.0f - (particle->age / particle->duration) : 1.0f;

    GLfloat mat_emission[] = { color[0], color[1], color[2], fade };

    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);

    glBegin(GL_POINTS);
    glVertex3f(0, 0,  0);
    glEnd();
}

void Cloud::render(entityx::Entity entity, float dt) {
    entityx::ptr<Particle> particle = entity.component<Particle>();
    GLfloat fade = particle? 1.0f - (particle->age / particle->duration) : 1.0f;
    GLfloat size = (particle? particle->age : 1.0f) * grow_speed;

    GLfloat mat_emission[] = { color[0] * fade,
                               color[1] * fade,
                               color[2] * fade,
                               fade };

    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emission);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_emission);

    glPushMatrix();
    glScalef(size, size, 0);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();
}

