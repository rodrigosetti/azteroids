#include <OpenGL/gl.h>

#include "app.h"

App::App(int width, int height) :
    width(width), height(height), level(Level(this)) {
    level.start();
}

void App::initialize() {
    const GLfloat light_position0[] = { 0.0, 0.0, 1.0, 0.0 };
    const GLfloat light_diffuse0[] = { 10.0, 10.0, 10.0, 1.0 };

    const GLfloat light_position1[] = { 0.0, -1.0, 0.0, 0.0 };
    const GLfloat light_diffuse1[] = { 10.0, 10.0, 50.0, 1.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
    glEnable(GL_LIGHTING);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
    glEnable(GL_LIGHT1);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, 0.1f, 1000);
}

void App::step(double dt) {
    level.step(dt);
}

