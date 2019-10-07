/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Barbarian class implementation file
*****************************************************/
#include "Barbarian.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using std::string;


// default constructor with attack and defense initialized 
// to 0 (because determined by rolls) and defeat condition
// initialized to false 
Barbarian::Barbarian()                             
{
	CharacterType = "Barbarian";
	attack_Point = 0;
	defense_Point = 0;
	armor_Point = 0;
	strength_Point = 12;
	defeat = false;
}

// destructor
Barbarian::~Barbarian()                          
{
}

// function to roll dice for attack points
int Barbarian::attack_Roll()
{
	int atk = rand() % 6 + 1;
	atk = atk + (rand() % 6 + 1);
	return atk;
}

// function to roll dice for defense points
int Barbarian::defense_Roll()
{
	int defense = rand() % 6 + 1;
	defense = defense + (rand() % 6 + 1);
	return defense;
}

// getters for character type, armor, strength points
string Barbarian::get_Type()                       
{
	return CharacterType;
}

int Barbarian::get_Strength()
{
	return strength_Point;
}

int Barbarian::getArmor()
{
	return armor_Point;
}

// bool for character defeat status
bool Barbarian::defeated()
{
	return defeat;
}
// calls attack_roll function and prints attack points
int Barbarian::attack()                            
{
	attack_Point = attack_Roll();
	std::cout << "The Barbarian uses " << attack_Point << " attack points!" << std::endl;
	return attack_Point;
}

// defend function calls defense roll and prints prompts based on damage
void Barbarian::defend(int a)                      
{
	int damage = a;
defense_Point = defense_Roll();

	// if medusa special ability (causes 100 damage), barbarian is defeated
	if (damage == 100)
	{
		std::cout << "The Barbarian has succumb to Medusa's special ability,glare, and has turned into stone!" << std::endl;
		std::cout << "The baribarian's strength points is now 0." << std::endl;
		defeat = true;
	}

	// otherwise print defense points, armor, and amount of damage received
	else
	{
		std::cout << "The Barbarian uses " << defense_Point << " defense points!" << std::endl;

		damage = damage - defense_Point;

		std::cout << "The Barbarian uses " << armor_Point << " armor." << std::endl;

		damage = damage - armor_Point;

		std::cout << "The Barbarian recieved " << damage << " points in damage." << std::endl;

		if (damage > 0)
		{
			strength_Point = strength_Point - damage;
		}
		else
		{
			strength_Point = strength_Point;
		}

		// continue loop until character is defeated
		if (strength_Point > 0)
		{
			std::cout << "The Barbarian is stil alive!" << std::endl;
			std::cout << "Strength points remaining: " << strength_Point << std::endl << std::endl;
		}
		else if (strength_Point <= 0)
		{
			std::cout << "Barbarian is defeated." << std::endl;
			std::cout << "Strength points remaining: 0" << std::endl << std::endl;
			defeat = true;
		}
	}
}
