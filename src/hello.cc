//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================
#include <world.h>
#include "hello.h"


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

hello::hello(const hello &h) {
    hellop = new hello_pimpl;
    *hellop = *h.hellop;
}

std::string hello::get_hello(void) {
    std::string s;
    world w;

    s = "Hello, "+ hellop->w.get_world() + "!\n";

    return s;
}
