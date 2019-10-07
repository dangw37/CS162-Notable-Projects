/*************************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Header file for the HarryPotter class
**************************************************************/
#ifndef HarryPotter_HPP
#define HarryPotter_HPP

#include "Character.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>

using std::string;

// Harry Potter class declaration
class HarryPotter : public Character                      
{
public:
	HarryPotter();
	~HarryPotter();
	int attack_Roll();
	int defense_Roll();
	string get_Type();
	int attack();
	void defend(int damage);
	int getArmor();
	int get_Strength();

	

	

	bool defeated();
};

#endif