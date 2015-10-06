/**
 * @file      world.h
 * @copyright (C) 2015 Fujitsu Network Communications, Inc.
 * @brief     World API
 *
 * @author    Your favorite person
 * @date      3/2015
 *
 * Document Reference :
 */
#ifndef HELLOWORLD_WORLD_WORLD_H_
#define HELLOWORLD_WORLD_WORLD_H_

#include <string>

/**
 * @addtogroup external
 * World External Interfaces
 * @{
 */

class World_pimpl;

/**
 * World class
 *
 * Refer to Hello class for further doxygen examples.
 */
class World {
 public:
  World(void);
  World(const World &other);
  World& operator=(const World &other);
  ~World(void);

  /**
   * get World string
   * @retval string "World"
   */
  std::string GetWorld(void) const;

 private:
  World_pimpl *worldp_;
};

/**
 * @}
 */

#endif  // HELLOWORLD_WORLD_WORLD_H_
