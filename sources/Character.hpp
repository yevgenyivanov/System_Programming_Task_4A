#pragma once
#include <string>
#include "Character.hpp"
#include "Point.hpp"
class Character
{
private:
    std::string _name;
    int _hitPoints;
    Point _currLocation;

public:
    // constructor
    Character(const std::string &, int, Point);
    // copy constructor
    Character(Character &) noexcept;
    // copy assignment operator
    Character &operator=(const Character &) noexcept;
    // move constructor
    Character(Character &&) noexcept;
    // move assignment operator
    Character &operator=(Character &&) noexcept;
    // destructor
    virtual ~Character();

    bool isAlive();
    double distance(Character &);
    void hit(int);
    std::string getName();
    Point getLocation();
    std::string print();
    // helper func
    virtual void attack(Character *);
    int get_hp();
    
};
namespace ariel
{
};