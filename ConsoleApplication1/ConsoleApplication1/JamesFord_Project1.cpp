/*
James Ford - studentID : 2523352
C++ Programing 
3 - 1 - 2017
*/

#include <iostream>
#include <vector>
#include <ctime>
//#include "Monster.h"
#include "Pokeball.h"

void ranAway(Pokeball x, int y);
void tryCatch(Monster x, Pokeball y, int z, int &caught, vector <Monster> &pokeTeam);

int main()
{
	Monster monster;
	vector <Monster> pokeTeam;
	char input;
	bool didCatch = false;
	Pokeball pokeballs;
	int caught = 0;


	cout << "\n Welcome the the amazing world of Pokemon!"
		<< "\n\n This new world to explore will bring great adventure!"
		<< "\n The time is now, go on and take your destiny!"
		<< "\n But remember not to run out of Pokeballs!"
		<< "\n You luckily have 5 PokeBalls to begin your quest to be a Pokemon Master!\n\n";
	system("pause");

	for (int i = 1; pokeballs.pokeballs > 0; i++)
	{
		input = NULL;
		
		// Beginning & pointless choices
		cout << "\n\n Walk to the [L]eft or to the [R]ight?\n >: ";
		cin >> input;
		input = toupper(input);
		while (input != 'L' && input != 'R')
		{
			cout << "\n Please, pick a path, [L]eft or [R]ight?\n >: ";
			cin >> input;
			input = toupper(input);
		} 
		input = NULL;
		
		// Monster appear
		monster = monster.setMonster(monster);
		cout << "\n A " << monster.Name << " has appeared! Get Ready!\n It has a Combat Power of " << monster.combatPower << "!";
		cout << "\n\n Remaining PokeBalls : " << pokeballs.pokeballs << " :"
			<< "\n What will you do? [R]un or attempt to [C]apture?\n >: ";
		cin >> input;
		input = toupper(input);
		while (input != 'R' && input != 'C')
		{
			cout << "\n Please, pick an option, [R]un or [C]apture?\n >: ";
			cin >> input;
			input = toupper(input);
		}
		if (input == 'R')
		{
			ranAway(pokeballs, i);
		}
		else
		{
			input = NULL;
			pokeballs.pokeballs--;
			cout << "\n\n Pulling out a PokeBall, you throw a balanced pitch."
				<< "\n It flys towards and hits the " << monster.Name << " on the top of the head!"
				<< "\n Inside the PokeBall is a restless monster, you wait to see what will happen.\n\n";
			system("pause");
			
			// Check if caught
			didCatch = pokeballs.captureAttempt(monster);
			if (didCatch)
			{
				caught++;
				pokeTeam.push_back(monster);
				cout << "\n\n You did it! You caught the " << monster.Name << "!"
					<< "\n Now you are one step closer to becoming a Pokemon Master!"
					<< "\n With " << monster.Name << "'s " << monster.combatPower << " Combat Power, you are ready for anything!\n\n";
				system("pause");
				cout << "\n\n You look in your bag, " << pokeballs.pokeballs << " PokeBalls left."
					<< "\n You return to the road and begin to walk once more.";
			}
			else
			{
				cout << "\n\n " << monster.Name << " popped out of the PokeBall!"
					<< "\n You are stunned from the failure, but regain momentum!";
				
				//Failed and trying again
				if (pokeballs.pokeballs != 0)
				{
					cout << "\n You look in your bag, " << pokeballs.pokeballs << " PokeBalls left."
						<< "\n Do you [Run] or attempt to [C]apture the " << monster.Name << " again?\n >: ";
					cin >> input;
					input = toupper(input);
					while (input != 'R' && input != 'C')
					{
						cout << "\n Please, pick an option, [R]un or [C]apture?\n >: ";
						cin >> input;
						input = toupper(input);
					}
					if (input == 'R')
						ranAway(pokeballs, i);
					else
						tryCatch(monster, pokeballs, i, caught, pokeTeam);
				}
			}
		}
	}
	cout << "\n You ran out of PokeBalls, and so ends your adventure..."
		<< "\n You caught " << caught << " Pokemon!";
	for (int i = 0; i < pokeTeam.size(); i++)
		cout << "\n : Name > " << pokeTeam[i].Name << "\n      : CP > " << pokeTeam[i].combatPower;
	cout << "\n You run back down the road, safely home.\n\n";
	system("pause");
	exit(0);
}

void tryCatch(Monster x, Pokeball y, int z, int &caught, vector <Monster> &pokeTeam)
{
	y.pokeballs--;
	char input = NULL;
	cout << "\n You brace yourself once again, this time you won't be beaten!"
		<< "\n Throwing a PokeBall straight at the " << x.Name << "!"
		<< "\n There! " << x.Name << " got pulled in the PokeBall once more!\n\n";
	system("pause");
	if (y.captureAttempt(x))
	{
		caught++;
		pokeTeam.push_back(x);
		cout << "\n\n You did it! You caught the " << x.Name << "!"
			<< "\n Now you are one step closer to becoming a Pokemon Master!"
			<< "\n With " << x.Name << "'s " << x.combatPower << " Combat Power, you are ready for anything!\n\n";
		system("pause");
		cout << "\n\n You look in your bag, " << y.pokeballs << " PokeBalls left."
			<< "\n You return to the road and begin to walk once more.";
	}
	else
	{
		cout << "\n\n " << x.Name << " popped out of the PokeBall!"
			<< "\n You are stunned from the failure, but regain momentum!";
		if (y.pokeballs != 0)
		{
			cout << "\n You look in your bag, " << y.pokeballs << " PokeBalls left."
				<< "\n Do you [Run] or attempt to [C]apture the " << x.Name << " again?\n >: ";
			cin >> input;
			input = toupper(input);
			while (input != 'R' && input != 'C')
			{
				cout << "\n Please, pick an option, [R]un or [C]apture?\n >: ";
				cin >> input;
				input = toupper(input);
			}
			if (input == 'R')
				ranAway(y, z);
			else
				tryCatch(x, y, z, caught, pokeTeam);
		}
	}
}

void ranAway(Pokeball x, int y)
{
	char input = NULL;
	cout << "\n You ran out of there, safe however."
		<< "\n You look in your bag, " << x.pokeballs << " PokeBalls left."
		<< "\n Would you like to return to the road? [Y/N]\n >: ";
	cin >> input;
	input = toupper(input);
	while (input != 'Y' && input != 'N')
	{
		cout << "\n Please, pick an option, [Y]es or [N]o?\n >: ";
		cin >> input;
		input = toupper(input);
	}
	if (input == 'N')
	{
		cout << "\n You retire your Pokemon career. You give up on this once inspiring life."
			<< "\n With only " << y << " travels under your name and " << x.pokeballs << " PokeBalls left, you fear you could've done more."
			<< "\n [END]...\n\n";
		system("pause");
		exit(0);
	}
}