#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <list>

// Character class
class Character {
	private:
		std::string name;
		int health;
	public:
		Character(std::string n, int h);
		void display() const;
		std::string getName() const;
		int getHealth() const;
		void setHealth(int h);
};

#endif // CHARACTER_H

