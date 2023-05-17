#include <stdexcept>
#include "Team2.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
using namespace ariel;
Team2::Team2(Character *_Team2Leader)
{
    if (!_teamMembers.empty())
        throw std::runtime_error("Team2 leader already assigned");

    this->_teamMembers.emplace_back(_Team2Leader);
}

// copy constructor
Team2::Team2(Team2 &) {}
// copy assignment operator
Team2 &Team2::operator=(const Team2 &_otherTeam2) noexcept 
{
    this->_teamMembers= _otherTeam2._teamMembers;
    return *this;
}
// move constructor
Team2::Team2(Team2 &&_otherTeam2) noexcept {}
// move assignment operator
Team2 &Team2::operator=(Team2 &&_otherTeam2) noexcept 
{
    return _otherTeam2=*this;
}
// destructor
Team2::~Team2() {}

void Team2::add(Character *_char)
{
}
// void Team2::add(Cowboy *){}

void Team2::attack(Team2 *_enemyTeam2) {}
int Team2::stillAlive() { return 0; }
void Team2::print() {}