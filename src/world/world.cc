/**
 * @file      world.cc
 * @copyright (C) 2015 Fujitsu Network Communications, Inc.
 * @brief     ...
 *
 * @author    Your favorite person
 * @date      3/2015
 *
 * Document Reference :
 */
#include "world/world.h"
#include <algorithm>

/**
 * @brief World private implementation
 *
 * Using pimpl pattern allows private implementation to change in future
 * without requiring a recompile of hello since include file doesn't change.
 */
class World_pimpl {
 public:
  World_pimpl(void) : s(std::string("World")) {}
  std::string s;
};

World::World(void) {
  worldp = new World_pimpl;
}

World::~World(void) {
  delete worldp;
}

World::World(const World &other) {
  worldp = new World_pimpl;
  *worldp = *other.worldp;
}

World& World::operator=(const World &other) {
  if (this != &other) {
    World tmp(other);
    std::swap(worldp, tmp.worldp);
  }
  return *this;
}

std::string World::get_world(void) const {
  return worldp->s;
}
