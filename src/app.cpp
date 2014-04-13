#include <OpenGL/gl.h>

#include "app.h"

App::App(int width, int height) :
    width(width), height(height), level(Level(width, height)) {
    level.start();
}

void App::initialize() {
    const GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };
    const GLfloat light_diffuse[] = { 100.0, 100.0, 100.0, 1.0 };

    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, 0.1f, 1000);
}

void App::step(double dt) {
    level.step(dt);
}

