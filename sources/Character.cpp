#include "Character.hpp"
#include <string>
#include <iostream>
using namespace ariel;
// constructor
Character::Character(const std::string &name, int hitpoints, Point location) : _name(name), _hitPoints(hitpoints), _currLocation(location) {}
// copy constructor
Character::Character(Character &_otherChar) noexcept {}
// copy assignment operator
Character &Character::operator=(const Character &_otherChar) noexcept
{
    this->_currLocation = _otherChar._currLocation;
    this->_hitPoints = _otherChar._hitPoints;
    this->_name = _otherChar._name;
    return *this;
}
// move constructor
Character::Character(Character &&_otherChar) noexcept {}
// move assignment operator
Character &Character::operator=(Character &&_otherChar) noexcept
{
    return _otherChar = *this;
}
// destructor
Character::~Character() {}

bool Character::isAlive()
{
    return false;
}

double Character::distance(Character &_other)
{
    return 0.0;
}

void Character::hit(int _damage)
{
    // pass
}
std::string Character::getName()
{
    return "";
}
Point Character::getLocation()
{
    return Point(0.0, 0.0);
}

std::string Character::print()
{
    // std::cout << "pass." << std::endl;
    // pass
    return "";
}
//
void Character::attack(Character *_target)
{
    // pass
}
int Character::get_hp()
{
    return this->_hitPoints;
}
