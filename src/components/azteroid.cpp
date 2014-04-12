#include <GL/glut.h>
#include "azteroid.h"

void Azteroid::render() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glutSolidCube(1);
}

