#include <ctime>
#include "Pokeball.h"

Pokeball::~Pokeball()
{
}

bool Pokeball::captureAttempt(Monster x)
{
	int chance;
	if (x.combatPower >= 1 && x.combatPower <= 99)
	{
		chance = 2;
	}
	else if (x.combatPower >= 100 && x.combatPower <= 199)
	{
		chance = 4;
	}
	else
	{
		chance = 8;
	}

	srand(time(NULL));
	if (rand() % chance == 0)
		return true;
	else
		return false;
}