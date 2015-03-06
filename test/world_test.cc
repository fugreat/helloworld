/**
 * @file world_test.cc
 * @brief world Unit Tests
 */
#include <assert.h>
#include <string>
#include "world.h"

static void world_test(void)
{
    world w;
    std::string s = w.get_world();

    assert(s == "World");
}

int main(int argc, char *argv[])
{
    world_test();

    return 0;
}
