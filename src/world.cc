//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================
#include <world.h>

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

world::world(const world &w) {
    worldp = new world_pimpl;
    *worldp = *w.worldp;
}

std::string world::get_world(void) {
    return worldp->s;
}
