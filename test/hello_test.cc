/**
 * @file hello_test.cc
 * @brief hello Unit Tests
 */
#include "hello.h"
#include "gtest/gtest.h"

class Hello_test : public ::testing::Test {
};

TEST_F(Hello_test, copy) {
  Hello h1;
  Hello h2(h1);

  std::string s = h2.get_hello();

  ASSERT_EQ(s, "Hello, World!\n");
}

TEST_F(Hello_test, assign) {
  Hello h1;
  Hello h2;

  // Return type of assignment operator is current object by reference.
  ASSERT_EQ(&(h2 = h1), &h2);

  // Test logic related to self assignment
  ASSERT_EQ(&(h1 = h1), &h1);
}

TEST_F(Hello_test, get_hello) {
  Hello h;
  std::string s = h.get_hello();

  ASSERT_EQ(s, "Hello, World!\n");
}
