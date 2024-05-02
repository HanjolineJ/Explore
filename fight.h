#ifndef FIGHT_H
#define FIGHT_H

#include "character.h"
#include <iostream>
#include <string>

class Fight {
	public:
		static void bearAttack(int& health);
		void initiate(Character& player, Character& enemy);
		void resolve(Character& player, Character& enemy, const std::string& action);
};

#endif // FIGHT_H

