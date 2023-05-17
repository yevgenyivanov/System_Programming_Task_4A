#include <stdexcept>
#include "Team.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
using namespace ariel;
Team::Team(Character *_teamLeader)
{
    if (!_teamMembers.empty())
        throw std::runtime_error("Team leader already assigned");

    this->_teamMembers.emplace_back(_teamLeader);
}

// copy constructor
Team::Team(Team &) {}
// copy assignment operator
Team &Team::operator=(const Team &_otherTeam) noexcept 
{
    this->_teamMembers= _otherTeam._teamMembers;
    return *this;
}
// move constructor
Team::Team(Team &&_otherTeam) noexcept {}
// move assignment operator
Team &Team::operator=(Team &&_otherTeam) noexcept 
{
    return _otherTeam=*this;
}
// destructor
Team::~Team() {}

void Team::add(Character *_char)
{
}
// void Team::add(Cowboy *){}

void Team::attack(Team *_enemyTeam) {}
int Team::stillAlive() { return 0; }
void Team::print() {}