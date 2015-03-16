/**
 * @file hello_test.cc
 * @brief hello Unit Tests
 */
#include <assert.h>
#include "../src/hello.h"
#include "gtest/gtest.h"

class hello_test : public ::testing::Test {
};

TEST_F(hello_test, get_hello)
{
    hello h;
    std::string s = h.get_hello();

    assert(s == "Hello, World!\n");
}
