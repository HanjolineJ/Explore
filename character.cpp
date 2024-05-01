#include "character.h"
#include <iostream>

// Constructor
Character::Character(std::string n, int h, int s) : name(n), health(h), strength(s) {}

// Display the character's stats
void Character::display() const {
    std::cout << "Name: " << name << ", Health: " << health << ", Strength: " << strength << std::endl;
}

// Get the character's name
std::string Character::getName() const {
	return name;
}

