#include "fight.h"

//void Fight::initiate(Character& player, Character& enemy) {
//	std::cout << "You encounter a " << enemy.getName() << "!" << std::endl;
//	std::cout << "Will you run or fight? (r/f): " << std::endl;
//}

//void Fight::resolve(Character& player, Character& enemy, const std::string& action) {
//	if (action == "f") {
//		std::cout << "You are brave and decide to fight!" << std::endl;
//		// Implement logic to determine if player wins or loses
//		std::cout << "You defeated the " << enemy.getName() << "!" << std::endl;
//	} else if (action == "r") {
//		std::cout << "You are smart and run fast towards the sound of water!" << std::endl;
//	} else {
//		std::cout << "You must choose to run or fight! Hurry, the " << enemy.getName() << " is getting closer!" << std::endl;
//	}
//}
void Fight::bearAttack(int& health) {
	health -= 25;
	if (health <= 0) {
		std::cout << "You didn't escape, do you want to play again? (yes/no): ";
	}
}

