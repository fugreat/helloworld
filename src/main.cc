//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================
#include <iostream>
#include "hello.h"

int main(int argc, const char *argv[]) {
    (void)argc;
    (void)argv;
    hello h;

    std::cout << h.get_hello();
}
