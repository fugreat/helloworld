/**
 * @file world_test.cc
 * @brief world Unit Tests
 */
#include <assert.h>
#include <string>
#include <world.h>
#include "gtest/gtest.h"

class world_test : public ::testing::Test {
};

TEST_F(world_test, get_world)
{
    world w;
    std::string s = w.get_world();

    assert(s == "World");
}
