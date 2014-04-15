#pragma once

#include <entityx/entityx.h>

enum class EntityIdentity { ASTEROID, SHIP, LASER };

struct Identity : entityx::Component<Identity> {
    Identity(EntityIdentity identity) : identity(identity) {}

    EntityIdentity identity;
};

