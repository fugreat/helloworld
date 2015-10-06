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
#ifndef HELLOWORLD_HELLO_H_
#define HELLOWORLD_HELLO_H_

#include <string>

namespace hello {

/**
 * @addtogroup internal
 * Hello Internal Interfaces
 * @{
 */

class Hello_pimpl;

/**
 * Hello class provides hello functionality.
 *
 * Use a newline and a 4-space indent to provide special formatting.  As an
 * example, the following shows example usage in a special code box on the
 * doxygen page:
 *
 *     Hello h;
 *     (void) h.get_hello();
 */
class Hello {
 public:
  Hello(void);
  Hello(const Hello &other);
  Hello& operator=(const Hello &other);
  ~Hello(void);

  /**
   * get Hello string
   * @retval string "Hello, World!\n".
   */
  std::string GetHello(void) const;

  /**
   * Some other function
   * @param whatever Some integer value
   */
  void OtherFunction(const int whatever) {}

 private:
  Hello_pimpl* hellop_;
};

/**
 * @}
 */

}  // namespace hello
#endif  // HELLOWORLD_HELLO_H_
