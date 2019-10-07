/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Implementation file for Medusa class
*****************************************************/
#include "Medusa.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using std::string;


// default constructor with attack and defense initialized 
// to 0 (because determined by rolls) and defeat condition
// initialized to false. 
Medusa::Medusa()                               
{
	CharacterType = "Medusa";
	attack_Point = 0;
	defense_Point = 0;
	armor_Point = 3;
	strength_Point = 8;
	defeat = false;
}

// destructor
Medusa::~Medusa()                              
{
}

// function to roll dice for randomized attack points
int Medusa::attack_Roll()                           
{
	int atk = rand() % 6 + 1;
	atk = atk + (rand() % 6 + 1);
	return atk;
}

// defend function calls defense roll and prints prompts based on damage
int Medusa::defense_Roll()                          
{
	int defense = rand() % 6 + 1;
	return defense;
}

// getters for character type, armor, strength points
string Medusa::get_Type()                      
{
	return CharacterType;
}

int Medusa::get_Strength()
{
	return strength_Point;
}

int Medusa::getArmor()                             
{
	return armor_Point;
}

// bool for character defeat status
bool Medusa::defeated()                            
{
	return defeat;
}

// calls attack_roll function and prints attack points, also calls her special ability which sets attack points to 100
int Medusa::attack()                             
{
	attack_Point = attack_Roll();
	if (attack_Point == 12)
	{
		std::cout << "Medusa has called upon her special ability to use glare and turn her opponent into stone!" << std::endl;
		return attack_Point = 100;
	}
	else
	{
		std::cout << "Medusa uses " << attack_Point << " attack points!" << std::endl;
		return attack_Point;
	}
}

// defend function calls defense roll and prints prompts based on damage
void Medusa::defend(int a)                     
{
	int damage = a;
	defense_Point = defense_Roll();

	// print prompt if special ability used
	if (damage == 100)
	{
		std::cout << "The Medusa has succumb fallen to the other Medusa's glare and turns into stone!" << std::endl;
		std::cout << "Medusa's strength points is now 0" << std::endl << std::endl;
		defeat = true;
	}
	// otherwise print defense points, armor, and amount of damage received
	else
	{
		std::cout << "Medusa uses " << defense_Point << " defense points!" << std::endl;
		damage = damage - defense_Point;

		std::cout << "Medusa uses " << armor_Point << " armor." << std::endl;
		damage = damage - armor_Point;

		std::cout << "Medusa received " << damage << " points in damage." << std::endl;

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
			std::cout << "Medusa is still alive!" << std::endl;
			std::cout << "Strength points remaining: " << strength_Point << std::endl << std::endl;
		}
		else if (strength_Point <= 0)
		{
			std::cout << "Medusa is defeated." << std::endl;
			std::cout << "Strength points remaining: 0" << std::endl << std::endl;
			defeat = true;
		}
	}
}
