/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Implementation file for HarryPotter class
*****************************************************/
#include "HarryPotter.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;

// default constructor with attack and defense initialized 
// to 0 (because determined by rolls) and defeat condition
// initialized to false. 
HarryPotter::HarryPotter()                             
{
	CharacterType = "Harry Potter";
	attack_Point = 0;
	defense_Point = 0;
	armor_Point = 0;
	strength_Point = 10;
	defeat = false;
}

// destructor
HarryPotter::~HarryPotter()                           
{
}

// function to roll dice for randomized attack points
int HarryPotter::attack_Roll()
{
	int atk = rand() % 6 + 1;
	atk = atk + (rand() % 6 + 1);
	return atk;
}

// function to roll dice for randomized defense points
int HarryPotter::defense_Roll()
{
	int defense = rand() % 6 + 1;
	defense = defense + (rand() % 6 + 1);
	return defense;
}

// getters for character type, armor, strength points
string HarryPotter::get_Type()                             
{
	return CharacterType;
}

int HarryPotter::get_Strength()
{
	return strength_Point;
}

int HarryPotter::getArmor()
{
	return armor_Point;
}

// bool for character defeat status
bool HarryPotter::defeated()                                   
{
	return defeat;
}

// calls attack_roll function and prints attack points
int HarryPotter::attack()                                
{
	attack_Point = attack_Roll();
	std::cout << "Harry Potter uses " << attack_Point << " attack points!" << std::endl;
	return attack_Point;
}

// defend function calls defense roll and prints prompts based on damage
void HarryPotter::defend(int d)                        
{
	int damage = d;
	bool hogwarts = true;
	defense_Point = defense_Roll();

	if (damage == 100)
	{
		std::cout << "Harry Potter has succumb to Medusa's glare and turns into stone!" << std::endl;
		std::cout << "Strength Points: 0" << std::endl << std::endl;
		strength_Point = 0;
		
		// activate character special ability to restore strength points to 20
		if (hogwarts == true)
		{
			std::cout << "Harry Potter activates his special ability Hogwarts!" << std::endl;
			std::cout << "Harry Potter is revived and returns with 20 strength points!" << std::endl;
			strength_Point = 20;
			hogwarts = false;
			defeat = false;
		}
		else if (hogwarts == false)
		{
			std::cout << "Harry Potter attempts to use his special ability Hogwarts!" << std::endl;
			std::cout << "It seems as though he has failed his attempt." << std::endl;
			defeat = true;
		}
	}
	// otherwise print defense points, armor, and amount of damage received
	else
	{
		std::cout << "Harry Potter uses " << defense_Point << " defense points!" << std::endl;
		damage = damage - defense_Point;

		std::cout << "Harry Potter uses " << armor_Point << " armor." << std::endl;
		damage = damage - armor_Point;

		std::cout << "Harry Potter received " << damage << " points in damage." << std::endl;

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
			std::cout << "Harry Potter is still alive!" << std::endl;
			std::cout << "Strength points remaining: " << strength_Point << std::endl << std::endl;
		}
		// if strength points 0 or below, activate speical ability
		else if ((strength_Point <= 0) && (hogwarts == true))
		{
			std::cout << "Harry Potter is defeated." << std::endl;
			std::cout << "Strength points remaining: 0" << std::endl;
			std::cout << "Harry Potter activates his special ability Hogwarts!" << std::endl;
			std::cout << "Harry Potter is revived with 20 strength points!" << std::endl;
			strength_Point = 20;
			std::cout << "Strength points remaining: 20" << std::endl << std::endl;
			defeat = false;
			hogwarts = false;
		}
		else if ((strength_Point <= 0) && (hogwarts == false))
		{
			std::cout << "Harry Potter is defeated." << std::endl;
			std::cout << "Strength Points: 0" << std::endl << std::endl;
			defeat = true;
		}
	}
}
