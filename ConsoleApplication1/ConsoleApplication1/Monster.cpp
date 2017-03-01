#include "Monster.h"
#include <ctime>

string Monster::randomNameGen()
{
	const unsigned int SIZE = 48;
	string name;
	string pokemon[SIZE]{
		"Charmander", "Bulbasaur", "Squrtile", "Pidgey", "Pikachu", "Sandshrew", "Sandslash", "Zubat", "Golbat", "Diglett", "Dugtrio", "Meowth", "Psyduck", "Primeape", "Growlithe", "Arcanine", "Kadabra", "Machop", "Machoke", "Ponyta", "Muk", "Cubone", "Gyarados", "Mankey", "Abra","Magikarp", "Eevee", "Rattata", "Vulpix", "Ninetales", "Scyther", "Jigglypuff", "Geodude", "Onix", "Staryu","Snorlax", "Mew", "Oddish", "Caterpie", "Weedle", "Butterfree", "Beedrill", "Venusaur", "Blastoise", "Charizard", "Zapdos", "Moltres", "Articuno"
	};
	srand(time(NULL));
	name = pokemon[rand() % SIZE];
	return name;
}

Monster Monster::setMonster(Monster x)
{
	int power;
	x.Name = randomNameGen();
	srand(time(NULL));
	x.combatPower = rand() % 450 + 1;
	if (x.Name == "Arcanine" || x.Name == "Gyarados" || x.Name == "Mew" || x.Name == "Venusaur" || x.Name == "Blastoise" || x.Name == "Charizard" || x.Name == "Zapdos" || x.Name == "Moltres" || x.Name == "Articuno")
	{
		power = x.combatPower;
		x.combatPower = rand() % 450 + 1;
		if (power < x.combatPower)
		{
			power = x.combatPower;
			x.combatPower = rand() % 450 + 1;
			if (power > x.combatPower)
				x.combatPower = power;
		}
		else
		{
			x.combatPower = rand() % 450 + 1;
			if (power > x.combatPower)
				x.combatPower = power;
		}
	}
	return x;
}


Monster::~Monster()
{
}
