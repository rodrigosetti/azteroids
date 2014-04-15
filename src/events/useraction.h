#pragma once

#include <entityx/entityx.h>

enum class UserActionType { UP, DOWN, LEFT, RIGHT };

struct UserAction : public entityx::Event<UserAction> {
    UserAction(UserActionType type) : type(type) {}

    UserActionType type;
};
