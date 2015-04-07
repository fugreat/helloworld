/**
 * @file      hello.h
 * @copyright (C) 2015 Fujitsu Network Communications, Inc.
 * @brief     Hello API
 *
 * @author    Your favorite person
 * @date      3/2015
 *
 * Document Reference :
 */

#ifndef HELLO_H_
#define HELLO_H_

#include <string>

class Hello_pimpl;

/**
 * @brief Example Hello class
 */
class Hello {
 public:
  Hello(void);
  Hello(const Hello &other);
  Hello& operator=(const Hello &other);
  ~Hello(void);

  /**
   * @brief get Hello string
   * @retval string "Hello, World!\n".
   */
  std::string get_hello(void) const;

 private:
  Hello_pimpl *hellop;
};

#endif
