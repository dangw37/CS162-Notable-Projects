/*************************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Header file for the Medusa class
**************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>

using std::string;

// Medusa class declaration
class Medusa : public Character                   
{
public:
	Medusa();
	~Medusa();

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