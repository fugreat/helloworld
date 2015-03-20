//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================

/**
 * @file hello.h
 * @brief hello API
 */
#ifndef HELLO_H_
#define HELLO_H_
#include <string>

class hello_pimpl;

/**
 * @brief Example hello class
 */
class hello {
 public:
     hello();
     hello(const hello &other);
     hello& operator=(const hello &other);
     ~hello();

     /**
      * @brief get hello string
      * @retval string "Hello, World!\n".
      */
     std::string get_hello(void) const;

 private:
     hello_pimpl *hellop;
};

#endif  // HELLO_H_
