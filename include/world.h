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
     world(const world &w);
     ~world();

     /**
      * @brief get world string
      * @retval string "World"
      */
     std::string get_world(void);

 private:
     world_pimpl *worldp;
};

#endif  // WORLD_H_
