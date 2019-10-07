/*************************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Header file for the BlueMen Class
**************************************************************/
#ifndef BlueMen_HPP
#define BlueMen_HPP

#include "Character.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using std::string;

// Blue Men class declaration
class BlueMen : public Character
{
public:
	BlueMen();
	~BlueMen();

	int attack_Roll();
	int defense_Roll();
	int getArmor();
	int get_Strength();
	string get_Type();
	bool defeated();
	int attack();
	void defend(int damage);
};
#endif