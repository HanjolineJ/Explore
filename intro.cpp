#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <list>

#include "character.h"
#include "map.h"
// #include "fight.h"

int main() {
	std::cout << "Welcome to Explore, a survial based game! " << std::endl;
	// Vector for  characters
	std::vector<Character> characters;

	std::string name;
	std::cout <<  "You woke up with no memory. You need to find a way out and survive.\n";
	std::cout <<  "You remember if lost in woods find water, find water to escape the woods.\n";
	std::cout << "Enter your character name: ";
	std::cin >> name; //lets player add name
	std::cout << "Here are your stats\n";
	characters.push_back(Character(name, 100, 75));//Display input name

	for (auto& character : characters) {
		character.display();
	}//Display characters

	Map gameMap;
	gameMap.addLocation("Forest", {{"north", "Field"}, {"east", "River"}, {"south", "Plains"}, {"west", "Cave"}},
			"You see paths that lead north to a field, east to a river, south to plains, and west to a cave.");

	gameMap.addLocation("Field", {{"south", "Forest"},{"east", "Cave"},{"west", "River"}, {"north", "Plains"}},
			"The path back to the forest is clear, and you can see the forest to the south.");

	gameMap.addLocation("River", {{"west", "Cave"},{"east", "Plains"},{"north", "Field"},{"south", "Forest"}},
			"The river flows swiftly here.");

	gameMap.addLocation("Plains", {{"north", "Forest"},{"south", "Field"},{"east", "River"},{"west", "Cave"}},
			"You can see the forest to the north.");

	gameMap.addLocation("Cave", {{"east", "Forest"},{"north", "Plains"},{"west", "Cave"},{"south", "Field"}},
			"The entrance to the cave is dark");

	char directionChar;
	std::string direction;
	do {
		std::cout << gameMap.describeCurrentLocation() << std::endl;
		std::cout << gameMap.getCurrentLocationDescription() << std::endl;
		std::cout << gameMap.getCurrentNarrative() << std::endl;
		std::cout << "Choose a direction to explore (N/E/S/W): ";
		std::cin >> directionChar;//input
		directionChar = std::toupper(directionChar);//uppercase

		//		switch (directionChar) {
		//			case 'N':
		//				direction = "north";
		//				break;
		//			case 'E':
		//				direction = "east";
		//				break;
		//			case 'S':
		//				direction = "south";
		//				break;
		//			case 'W':
		//				direction = "west";
		//				break;
		//			case 'Q':  // Add a quit option
		//				std::cout << "Exiting game. Thank you for playing!" << std::endl;
		//				return 0;  // Exit the game
		//			default:
		//				std::cout << "Invalid direction. Try again." << std::endl;
		//				continue;
		//		}
		direction = (directionChar == 'N') ? "north" :
			(directionChar == 'E') ? "east" :
			(directionChar == 'S') ? "south" :
			(directionChar == 'W') ? "west" : ""  ;

		if (directionChar == 'Q') {
			std::cout << "Exiting game. Thank you for playing!" << std::endl;
			break;
		}
		if (!gameMap.move(direction)) {
			//std::cout << "Invalid direction. Try again." << std::endl;
			std::cout << "Invalid direction. Please choose N, E, S, or W." << std::endl;
			continue;
		}	else if (gameMap.getCurrentLocation() == "River") {
			std::cout << "You hear the sound of running water growing stronger. ";
			std::cout << "Following it downstream, you find a small village. You are safe again. Congrats for making it out.\n";
			break;
		}


	} while (true);

	return 0;
}

