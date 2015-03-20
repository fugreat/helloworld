//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================
#include "hello.h"
#include <algorithm>
#include "world.h"

/**
 * @brief hello private implementation
 */
class hello_pimpl {
 public:
     hello_pimpl() {}
     world w;
};

hello::hello(void) {
    hellop = new hello_pimpl;
}

hello::~hello(void) {
    delete hellop;
}

hello::hello(const hello &other) {
    hellop = new hello_pimpl;
    *hellop = *other.hellop;
}

hello& hello::operator=(const hello &other) {
    if (this != &other) {
        hello tmp(other);
        std::swap(hellop, tmp.hellop);
    }
    return *this;
}

std::string hello::get_hello(void) const {
    std::string s;

    s = "Hello, "+ hellop->w.get_world() + "!\n";

    return s;
}
