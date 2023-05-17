#pragma once
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#include <vector>

class Team2
{
  std::vector<Character *> _teamMembers;

public:
  // constructor
  Team2(Character *);
  // copy constructor
  Team2(Team2 &);
  // copy assignment operator
  Team2 &operator=(const Team2 &) noexcept;
  // move constructor
  Team2(Team2 &&) noexcept;
  // move assignment operator
  Team2 &operator=(Team2 &&) noexcept;
  // destructor
  ~Team2();
  //
  void add(Character *);
  void attack(Team2 *);
  int stillAlive();
  void print();
};

namespace ariel
{
};