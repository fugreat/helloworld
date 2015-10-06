/**
 * @file      main.cc
 * @copyright (C) 2015 Fujitsu Network Communications, Inc.
 * @brief     ...
 *
 * @author    Your favorite person
 * @date      3/2015
 *
 * Document Reference :
 */
#include <iostream>
#include "helloworld/hello.h"

int main(int argc, const char *argv[]) {
  (void)argc;
  (void)argv;
  hello::Hello h;

  std::cout << h.GetHello();
}
