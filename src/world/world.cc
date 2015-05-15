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
 * World private implementation
 *
 * Using pimpl pattern allows private implementation to change in future
 * without requiring a recompile of hello since include file doesn't change.
 */
class World_pimpl {
 public:
  World_pimpl(void) : s(std::string("World")) {}
  std::string s;
};

World::World(void) : worldp_(new World_pimpl) {
}

World::~World(void) {
  delete worldp_;
}

World::World(const World &other) {
  worldp_ = new World_pimpl;
  *worldp_ = *other.worldp_;
}

World& World::operator=(const World &other) {
  if (this != &other) {
    World tmp(other);
    std::swap(worldp_, tmp.worldp_);
  }
  return *this;
}

std::string World::GetWorld(void) const {
  return worldp_->s;
}
