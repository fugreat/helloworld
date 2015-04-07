/**
 * @file      hello.cc
 * @copyright (C) 2015 Fujitsu Network Communications, Inc.
 * @brief     ...
 *
 * @author    Your favorite person
 * @date      3/2015
 *
 * Document Reference :
 */

#include "hello.h"
#include <algorithm>
#include "world/world.h"

/**
 * @brief Hello private implementation
 */
class Hello_pimpl {
 public:
  Hello_pimpl(void) {}
  World w;
};

Hello::Hello(void) {
  hellop = new Hello_pimpl;
}

Hello::~Hello(void) {
  delete hellop;
}

Hello::Hello(const Hello &other) {
  hellop = new Hello_pimpl;
  *hellop = *other.hellop;
}

Hello& Hello::operator=(const Hello &other) {
  if (this != &other) {
    Hello tmp(other);
    std::swap(hellop, tmp.hellop);
  }
  return *this;
}

std::string Hello::get_hello(void) const {
  std::string s;

  s = "Hello, "+ hellop->w.get_world() + "!\n";

  return s;
}
