/**
 * @file world_test.cc
 * @brief world Unit Tests
 */
#include "helloworld/world/world.h"
#include "gtest/gtest.h"

class World_test : public ::testing::Test {
};

TEST_F(World_test, copy)
{
    World w1;
    World w2(w1);

    std::string s = w2.GetWorld();

    ASSERT_EQ(s, "World");
}

TEST_F(World_test, assign)
{
    World w1;
    World w2;

    // Return type of assignment operator is current object by reference.
    ASSERT_EQ(&(w2 = w1), &w2);

    // Test logic related to self assignment
    ASSERT_EQ(&(w1 = w1), &w1);
}

TEST_F(World_test, GetWorld)
{
    World w;
    std::string s = w.GetWorld();

    ASSERT_EQ(s, "World");
}
