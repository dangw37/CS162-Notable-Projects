/*************************************************************
** Author: William Dang
** Date: 7/21/2019
** Description: Header file for the Zoo class.
**************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;


// Vampire class declaration
class Vampire : public Character                      
{
public:
	Vampire();
	~Vampire();

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