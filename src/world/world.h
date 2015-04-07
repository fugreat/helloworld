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

#ifndef WORLD_WORLD_H_
#define WORLD_WORLD_H_

#include <string>

class World_pimpl;

/**
 * @brief Example World class
 */
class World {
 public:
  World(void);
  World(const World &other);
  World& operator=(const World &other);
  ~World(void);

  /**
   * @brief get World string
   * @retval string "World"
   */
  std::string get_world(void) const;

 private:
  World_pimpl *worldp;
};

#endif
