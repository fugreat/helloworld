//============================================================================
// Copyright (C) 2015 Fujitsu Network Communications, Inc. All Rights Reserved
//============================================================================

/**
 * @file world.h
 * @brief world API
 */
#ifndef WORLD_H_
#define WORLD_H_

#include <string>

class world_pimpl;

/**
 * @brief Example world class
 */
class world {
 public:
     world();
     world(const world &other);
     world& operator=(const world &other);
     ~world();

     /**
      * @brief get world string
      * @retval string "World"
      */
     std::string get_world(void) const;

 private:
     world_pimpl *worldp;
};

#endif  // WORLD_H_
