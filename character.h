#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <list>

// Character class
class Character {
	private:
		std::string name;
		int health;
		//int strength;
		//	std::list<std::string> inventory; // adding an inventory
	public:
		//int health;
		Character(std::string n, int h);
		void display() const;
		//	void addItem(const std::string& item);  // Adds an item to the inventory
		//	void removeItem(const std::string& item);  // Removes an item from the inventory
		//	void showInventory() const;  // Displays the contents of the inventory
		std::string getName() const;
		int getHealth() const;
		void setHealth(int h);
};

#endif // CHARACTER_H

