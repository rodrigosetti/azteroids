#include "app.h"

App::App() {
    level.start();
}

void App::step() {
    level.step(0.1);
}

