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
	std::cout <<  "You need to find a way out of the woods and survive.\n";
	std::cout <<  "You remember if lost in woods find water, find water to escape the woods.\n";
	std::cout << "Enter your character name: ";
	std::cin >> name; //lets player add name
	std::cout << "Here are your stats\n";
	characters.push_back(Character(name, 100));//Display input name

	for (auto& character : characters) {
		character.display();
	}//Display characters

	Map gameMap;
	gameMap.addLocation("Forest", {{"north", "Field"}, {"east", "River"}, {"south", "Plains"}, {"west", "Cave"}},
			"You see paths that lead north to a field, east to a river, south to plains, and west to a cave.");

	gameMap.addLocation("Field", {{"south", "Forest"}, {"east", "Cave"}, {"west", "Plains"}, {"north", "River"}},
			"The path back to the forest is clear, and you can see the forest to the south.");

	gameMap.addLocation("River", {{"west", "Field"}, {"east", "Plains"}, {"north", "Cave"}, {"south", "Forest"}},
			"The river flows nice here.");

	gameMap.addLocation("Plains", {{"north", "River"}, {"south", "Cave"}, {"east", "Forest"}, {"west", "Field"}},
			"You can see the forest to the north.");

	gameMap.addLocation("Cave", {{"east", "Forest"}, {"north", "Plains"}, {"west", "River"}, {"south", "Field"}},
			"The cave is dark.");

	char directionChar;
	std::string direction;
	do {
		std::cout << gameMap.describeCurrentLocation() << std::endl;
		std::cout << gameMap.getCurrentLocationDescription() << std::endl;
		std::cout << gameMap.getCurrentNarrative() << std::endl;
		std::cout << "Choose a direction to explore (N/E/S/W): ";
		std::cin >> directionChar;//input
		directionChar = std::toupper(directionChar);//uppercase
							    //
		direction = (directionChar == 'N') ? "north" :
			(directionChar == 'E') ? "east" :
			(directionChar == 'S') ? "south" :
			(directionChar == 'W') ? "west" : ""  ;

		if (directionChar == 'Q') {
			std::cout << "Exiting game. Thank you for playing!" << std::endl;
			break;
		}
		if (!gameMap.move(direction)) {
			std::cout << "Invalid direction. Please choose N, E, S, or W." << std::endl;
			continue;
		}	else if (gameMap.getCurrentLocation() == "River") {
			std::cout << "You hear the sound of running water growing stronger. ";
			std::cout << "Following it, you find a small village. Congrats for making it out, with " << characters[0].getHealth() << " health remaining." << std::endl;
			break;

		} else if (gameMap.getCurrentLocation() == "Cave") {
			std::cout << "A bear attacks as you enter the cave!\n";
			characters[0].setHealth(characters[0].getHealth() - 25);

			std::cout << "New Health: " << characters[0].getHealth() << std::endl;

			if (characters[0].getHealth() <= 0) {
				std::cout << "You died, do you want to play again? (yes/no): ";
				std::string input;
				std::cin >> input;
				if (input == "yes") {
					characters[0].setHealth(100);
				} else {
					std::cout << "Game Over!\n";
					break;  // Exit the game loop
				}
			}
		}



	} while (true);

	return 0;
}

