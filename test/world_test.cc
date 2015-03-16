/**
 * @file world_test.cc
 * @brief world Unit Tests
 */
#include <world.h>
#include "gtest/gtest.h"

class world_test : public ::testing::Test {
};

TEST_F(world_test, copy)
{
    world w1;
    world w2(w1);

    std::string s = w2.get_world();

    ASSERT_EQ(s, "World");
}

TEST_F(world_test, assign)
{
    world w1;
    world w2;

    w2 = w1;

    std::string s = w2.get_world();

    ASSERT_EQ(s, "World");
}

TEST_F(world_test, get_world)
{
    world w;
    std::string s = w.get_world();

    ASSERT_EQ(s, "World");
}
