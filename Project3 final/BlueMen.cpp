/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Implementation file for BlueMen Class
*****************************************************/

#include "BlueMen.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;

// default constructor with attack and defense initialized 
// to 0 (because determined by rolls) and defeat condition
// initialized to false 
BlueMen::BlueMen()                                 
{
	CharacterType = "Blue Men";
	attack_Point = 0;
	defense_Point = 0;
	armor_Point = 3;
	strength_Point = 12;
	defeat = false;
}

// destructor
BlueMen::~BlueMen()                                
{
}

// function to roll (2d10) dice for randomized attack points
int BlueMen::attack_Roll()                                  
{
	int atk = rand() % 10 + 1;
	atk = atk + (rand() % 10 + 1);
	return atk;
}

// function to roll dice for randomized defense points, set special condition (lose a defense die for every 4 strength points lost)
int BlueMen::defense_Roll()                                 
{
	if ((strength_Point <= 12) && (strength_Point >= 9))
	{
		std::cout << "Mob: The Blue Men are all standing strong! Three defense dice still used." << std::endl;
		int defense = rand() % 6 + 1;
		defense = defense + (rand() % 6 + 1);
		defense = defense + (rand() % 6 + 1);
		return defense;
	}
	else if ((strength_Point <= 8) && (strength_Point >= 5))
	{
		std::cout << "Mob: One of the Blue Men has fallen! Lost One defense die. 2 defense dies used." << std::endl;
		int defense = rand() % 6 + 1;
		defense = defense + (rand() % 6 + 1);
		return defense;
	}
	else if ((strength_Point <= 4) && (strength_Point >= 0))
	{
		std::cout << "Mob: Two of the Blue Men has fallen! Lost Two defense die. 1 defense dice used." << std::endl;
		int defense = rand() % 6 + 1;
		return defense;
	}
	return 0;
}

// getters for character type, armor, strength points
string BlueMen::get_Type()                          
{
	return CharacterType;
}

int BlueMen::get_Strength()                   
{
	return strength_Point;
}

int BlueMen::getArmor()                            
{
	return armor_Point;
}

// bool for character defeat status
bool BlueMen::defeated()                           
{
	return defeat;
}

// calls attack_roll function and prints attack points
int BlueMen::attack()                                
{
	attack_Point = attack_Roll();
	std::cout << "Blue Men attacks with " << attack_Point << " attack points!" << std::endl;
	return attack_Point;
}


// defend function calls defense roll and prints prompts based on damage
void BlueMen::defend(int a)                        
{
	int damage = a;
	defense_Point = defense_Roll();

	// if medusa special ability (causes 100 damage), Blue Men is defeated
	if (damage == 100)
	{
		std::cout << "The Blue Men have succumb to Medusa's glare and turn into stone!" << std::endl;
		std::cout << "The Blue Mens strength points is now 0" << std::endl << std::endl;
		defeat = true;
	}

	// otherwise print defense points, armor, and amount of damage received
	else
	{
		std::cout << "Blue Men uses " << defense_Point << " defense points!" << std::endl;
		damage = damage - defense_Point;

		std::cout << "Blue Men uses " << armor_Point << " armor." << std::endl;
		damage = damage - armor_Point;

		std::cout << "Blue Men recieved " << damage << " points in damage." << std::endl;

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
			std::cout << "Blue Men is still alive!" << std::endl;
			std::cout << "Strength Points remaining: " << strength_Point << std::endl << std::endl;
		}
		else if (strength_Point <= 0)
		{
			std::cout << "Blue Men is defeated." << std::endl;
			std::cout << "Strength Points: 0" << std::endl << std::endl;
			defeat = true;
		}
	}
}
