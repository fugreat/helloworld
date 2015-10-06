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

#include "helloworld/hello.h"
#include <algorithm>
#include "helloworld/world/world.h"

namespace hello {

/**
 * Hello private implementation
 */
class Hello_pimpl {
 public:
  Hello_pimpl(void) {}
  World w;
};

Hello::Hello(void) : hellop_(new Hello_pimpl) {
}

Hello::~Hello(void) {
  delete hellop_;
}

Hello::Hello(const Hello &other) {
  hellop_ = new Hello_pimpl;
  *hellop_ = *other.hellop_;
}

Hello& Hello::operator=(const Hello &other) {
  if (this != &other) {
    Hello tmp(other);
    std::swap(hellop_, tmp.hellop_);
  }
  return *this;
}

std::string Hello::GetHello(void) const {
  std::string s;

  s = "Hello, "+ hellop_->w.GetWorld() + "!\n";

  return s;
}

}  // namespace hello
