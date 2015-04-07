//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================
#include "world/world.h"
#include <algorithm>

/**
 * @brief world private implementation
 *
 * Using pimpl pattern allows private implementation to change in future
 * without requiring a recompile of hello since include file doesn't change.
 */
class world_pimpl {
 public:
     world_pimpl() : s(std::string("World")) {}
     std::string s;
};

world::world() {
    worldp = new world_pimpl;
}

world::~world() {
    delete worldp;
}

world::world(const world &other) {
    worldp = new world_pimpl;
    *worldp = *other.worldp;
}

world& world::operator=(const world &other) {
    if (this != &other) {
        world tmp(other);
        std::swap(worldp, tmp.worldp);
    }
    return *this;
}

std::string world::get_world(void) const {
    return worldp->s;
}
