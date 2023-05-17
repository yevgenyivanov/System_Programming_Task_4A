#pragma once
#include <vector>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

class Team
{
private:
    std::vector<Character *> _teamMembers = {};

public:
    // constructor
    Team(Character *);
    // copy constructor
    Team(Team &);
    // copy assignment operator
    Team &operator=(const Team &) noexcept;
    // move constructor
    Team(Team &&) noexcept;
    // move assignment operator
    Team &operator=(Team &&) noexcept;
    // destructor
    ~Team();
    //
    void add(Character *);
    void attack(Team *);
    int stillAlive();
    void print();
};

namespace ariel
{
};