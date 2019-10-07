/*************************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Header file for the Barbarian class.
**************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;

// Barbarian class declaration
class Barbarian : public Character               
{
public:
	Barbarian();
	~Barbarian();

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