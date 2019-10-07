/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Implementation file for Vampire class
*****************************************************/
#include "Vampire.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;

// default constructor with attack and defense initialized 
// to 0 (because determined by rolls) and defeat condition
// initialized to false. 
Vampire::Vampire()                                     
{
	CharacterType = "Vampire";
	attack_Point = 0;
	defense_Point = 0;
	armor_Point = 1;
	strength_Point = 12;
	defeat = false;
}

// destructor
Vampire::~Vampire()                                    
{
}

// function to roll dice for randomized attack points
int Vampire::attack_Roll()                              
{
	int atk = rand() % 12 + 1;
	return atk;
}

// function to roll dice for defense points
int Vampire::defense_Roll()                             
{
	int defense = rand() % 6 + 1;
	return defense;
}

// getters for character type, armor, strength points
string Vampire::get_Type()                              
{
	return CharacterType;
}

int Vampire::get_Strength()
{
	return strength_Point;
}

int Vampire::getArmor()
{
	return armor_Point;
}
// bool for character defeat status
bool Vampire::defeated()                               
{
	return defeat;
}

// calls attack_roll function and prints attack points
int Vampire::attack()                                    
{
	attack_Point = attack_Roll();
	std::cout << "Vampire attacks with " << attack_Point << " attack points!" << std::endl;
	return attack_Point;
}

// defend function calls defense roll and prints prompts based on special ability chance
void Vampire::defend(int a)                            
{
	int damage = a;
	defense_Point = defense_Roll();

	// set 50% randomized chance for special ability
	int charmChance = rand() % 2 + 1;

	if ((damage == 100) && (charmChance == 1))
	{
		std::cout << "The Vampire uses charm to keep Medusa from attacking." << std::endl;
		std::cout << "Strength Points: " << strength_Point << std::endl;
		defeat = false;
	}

	else if ((damage == 100) && (charmChance != 1))
	{
		std::cout << "The Vampire has succumb to Medusa's glare and turns into stone!" << std::endl;
		std::cout << "The Vampire's strength points is now 0" << std::endl;
		strength_Point = 0;
		defeat = true;
	}

	else if ((damage != 100) && (charmChance == 1))
	{
		std::cout << "Vampire uses its special ability Charm! Vampire's opponent cannot attack." << std::endl;
		std::cout << "Strength Points remaining: " << strength_Point << std::endl << std::endl;
		damage = 0;
	}

	// otherwise print defense points, armor, and amount of damage received
	else
	{
		std::cout << "Vampire uses " << defense_Point << " defense points!" << std::endl;
		damage = damage - defense_Point;

		std::cout << "Vampire uses " << armor_Point << " armor." << std::endl;
		damage = damage - armor_Point;

		std::cout << "Vampire received " << damage << " points in damage." << std::endl;

		if (damage > 0)
		{
			strength_Point = strength_Point - damage;
		}
		else
		{
			strength_Point = strength_Point;
		}

		if (strength_Point > 0)
		{
			std::cout << "Vampire is still alive!!" << std::endl;
			std::cout << "Strength points remaining: " << strength_Point << std::endl << std::endl;
		}
		else if (strength_Point <= 0)
		{
			std::cout << "Vampire is defeated." << std::endl;
			std::cout << "Strength points: 0" << std::endl << std::endl;
			defeat = true;
		}
	}
}
