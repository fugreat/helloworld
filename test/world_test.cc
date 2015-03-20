/**
 * @file world_test.cc
 * @brief world Unit Tests
 */
#include "../src/world.h"
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

    // Return type of assignment operator is current object by reference.
    ASSERT_EQ(&(w2 = w1), &w2);

    // Test logic related to self assignment
    ASSERT_EQ(&(w1 = w1), &w1);
}

TEST_F(world_test, get_world)
{
    world w;
    std::string s = w.get_world();

    ASSERT_EQ(s, "World");
}
