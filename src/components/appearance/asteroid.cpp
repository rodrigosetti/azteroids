#include <GL/glut.h>
#include "asteroid.h"

void Asteroid::render() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glutSolidCube(1);
}

