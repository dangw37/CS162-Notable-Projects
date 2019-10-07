/*************************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Header file for the Character class (base)
**************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;


// character (parent class) 
class Character                                              
{
protected:
	std::string CharacterType;

	int attack_Point;
	int defense_Point;
	int armor_Point;
	int strength_Point;
	bool defeat;

public:
	virtual string get_Type() = 0;
	virtual int getArmor() = 0;
	virtual int get_Strength() = 0;
	virtual int attack_Roll() = 0;
	virtual int defense_Roll() = 0;
	virtual int attack() = 0;
	virtual void defend(int damage) = 0;
	virtual bool defeated() = 0;
};

#endif