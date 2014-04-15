#include <components/appearance/ship.h>
#include <components/attrition.h>
#include <components/geometry.h>
#include <components/mass.h>
#include <components/momentum.h>
#include <components/position.h>

#include "usership.h"

const float LINEAR_MOMENTUM_STEP = 1000;
const float ANGULAR_MOMENTUM_STEP = 1000;

const float PI = 3.14159265359f;
const float DPI = 2 * PI;
const float HPI = 0.5f * PI;

void UserShip::initialize(entityx::ptr<entityx::EntityManager> entities,
                          entityx::ptr<entityx::EventManager> events) {
    // create entity's components
    entity = entities->create();
    entity.assign<Mass>(30);
    entity.assign<Ship>();
    entity.assign<Geometry>(10);
    entity.assign<Momentum>(0, 0, 0);
    entity.assign<Attrition>(0.6f, 0.5f);
    entity.assign<Position>(x, y);

    // subscribe to events
    events->subscribe<UserAction>(*this);
}

void UserShip::receive(const UserAction &action) {
    switch (action.type) {
        case UserActionType::UP:
            change_linear_momentum(LINEAR_MOMENTUM_STEP);
            break;
        case UserActionType::DOWN:
            change_linear_momentum(-LINEAR_MOMENTUM_STEP);
            break;
        case UserActionType::LEFT:
            change_angular_momemtum(ANGULAR_MOMENTUM_STEP);
            break;
        case UserActionType::RIGHT:
            change_angular_momemtum(-ANGULAR_MOMENTUM_STEP);
            break;
    }
}

void UserShip::change_angular_momemtum(float delta) {
    entityx::ptr<Momentum> momentum = entity.component<Momentum>();

    momentum->angular += delta;
}

void UserShip::change_linear_momentum(float delta) {
    entityx::ptr<Position> position = entity.component<Position>();
    entityx::ptr<Momentum> momentum = entity.component<Momentum>();
    entityx::ptr<Ship>     ship     = entity.component<Ship>();

    float angle = (position->rotation * DPI / 360.f) + HPI;
    momentum->x += cos(angle) * delta;
    momentum->y += sin(angle) * delta;

    ship->throttle();
}

