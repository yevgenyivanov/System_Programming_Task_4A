#pragma once
#pragma once
#include "Character.hpp"
#include <string>
class Cowboy : public Character
{
private:
    int _ammo;

public:
    Cowboy(std::string, Point);
    // ~Cowboy();

    void shoot(Character *);
    bool hasBoolets();
    void reload();
    void attack(Character *_target) override;
    // void *operator new(size_t);
    // void operator delete(void*);
};
