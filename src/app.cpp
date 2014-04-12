#include "app.h"

App::App(int width, int height) : level(Level(width, height)) {
    level.start();
}

void App::step(double dt) {
    level.step(dt);
}

