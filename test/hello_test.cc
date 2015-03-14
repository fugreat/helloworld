/**
 * @file hello_test.cc
 * @brief hello Unit Tests
 */
#include <assert.h>
#include "../src/hello.h"

static void hello_test(void)
{
    hello h;
    std::string s = h.get_hello();

    assert(s == "Hello, World!\n");
}

int main(int argc, char *argv[])
{
    hello_test();

    return 0;
}
