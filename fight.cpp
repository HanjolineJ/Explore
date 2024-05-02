#include "fight.h"

void Fight::bearAttack(int& health) {
	health -= 25;
	if (health <= 0) {
		std::cout << "You didn't escape, do you want to play again? (yes/no): ";
	}
}

