#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
Cowboy::Cowboy(std::string _name, Point _startingLocation) : Character::Character(_name, 110, _startingLocation), _ammo(6) {}

void Cowboy::shoot(Character *_target)
{
    // pass
}
bool Cowboy::hasBoolets()
{
    return false;
}
void Cowboy::reload()
{
    // pass
}
void Cowboy::attack(Character *_target)
{
    shoot(_target);
}

// void *Cowboy::operator new(size_t size){
//     void *ptr = malloc(size);
//     return ptr;
// }
// void Cowboy::operator delete(void *ptr){
//     free(ptr);
// }