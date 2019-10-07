/*****************************************************
** Author: William Dang
** Date: 8/4/2019
** Description: Main function runs fantasy game. User
** selects two characters to battle, and roll die
** until one of the characters die to represent this.
** Contains menu strings and prompts.
*****************************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Character.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include <string>

#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <limits>

using std::string;

int main()
{
	int player_1;
	int player_2;

	// player1 and player2 are pointers to Character, initialize to null
	Character* player1 = nullptr;                             
	Character* player2 = nullptr;                             

	Barbarian p1_Barbarian, p2_Barbarian;
	BlueMen p1_BlueMen, p2_BlueMen;
	HarryPotter p1_HarryPotter, p2_HarryPotter;
	Medusa p1_Medusa, p2_Medusa;
	Vampire p1_Vampire, p2_Vampire;

	// initialize to false until a player wins
	bool player1_Win = false;                       
	bool player2_Win = false;                      

	int play_Again;
	int firstMove;                                 
	int attack_Pwr;

	// changes to true if user exits
	bool game_End = false;                          

	do
	{
		std::cout << std::endl << "Welcome to the Fantasy Combat Game." << std::endl << std::endl;
		std::cout << "In this two-player game, each Player will choose a character for battle." << std::endl;
		std::cout << "Both players battle until one of their character dies (death = 0 strength points)." << std::endl << std::endl;

		std::cout << "Player 1, select a character: " << std::endl;
		std::cout << "1. Vampire " << std::endl;
		std::cout << "2. Barbarian " << std::endl;
		std::cout << "3. Blue Men " << std::endl;
		std::cout << "4. Medusa " << std::endl;
		std::cout << "5. Harry Potter " << std::endl << std::endl;

		std::cin >> player_1;

		while ((player_1 != 1) && (player_1 != 2) && (player_1 != 3) && (player_1 != 4) && (player_1 != 5))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Invalid. Please enter a valid choice: ";
			std::cin >> player_1;
		}

		switch (player_1)
		{
		case 1:
		{
			std::cout << "Player 1 has chosen the Vampire as his character!" << std::endl << std::endl;
			player1 = &p1_Vampire;
			break;
		}

		case 2:
		{
			std::cout << "Player 1 has chosen the Barbarian as his character!" << std::endl << std::endl;
			player1 = &p1_Barbarian;
			break;
		}

		case 3:
		{
			std::cout << "Player 1 has chosen the Blue Men as his character!" << std::endl << std::endl;
			player1 = &p1_BlueMen;
			break;
		}

		case 4:
		{
			std::cout << "Player 1 has chosen Medusa as his character!" << std::endl << std::endl;
			player1 = &p1_Medusa;
			break;
		}

		case 5:
		{
			std::cout << "Player 1 has chosen Harry Potter as his character!" << std::endl << std::endl;
			player1 = &p1_HarryPotter;
			break;
		}
		}

		std::cin.clear();
		std::cin.ignore();

		std::cout << "Player 2, select a character: " << std::endl;
		std::cout << "1. Vampire" << std::endl;
		std::cout << "2. Barbian" << std::endl;
		std::cout << "3. Blue Men" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Harry Potter" << std::endl << std::endl;

		std::cin >> player_2;

		while ((player_2 != 1) && (player_2 != 2) && (player_2 != 3) && (player_2 != 4) && (player_2 != 5))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Please enter a valid choice: ";
			std::cin >> player_2;
		}

		switch (player_2)
		{
		case 1:
		{
			std::cout << "Player 2 has chosen the Vampire as his character!" << std::endl << std::endl;
			player2 = &p2_Vampire;
			break;
		}

		case 2:
		{
			std::cout << "Player 2 has chosen the Barbarian as his character!" << std::endl << std::endl;
			player2 = &p2_Barbarian;
			break;
		}

		case 3:
		{
			std::cout << "Player 2 has chosen the Blue Men as his character!" << std::endl << std::endl;
			player2 = &p2_BlueMen;
			break;
		}

		case 4:
		{
			std::cout << "Player 2 has chosen Medusa as his character!" << std::endl << std::endl;
			player2 = &p2_Medusa;
			break;
		}

		case 5:
		{
			std::cout << "Player 2 has chosen Harry Potter as his character!" << std::endl << std::endl;
			player2 = &p2_HarryPotter;
			break;
		}
		}

		std::cin.clear();
		std::cin.ignore();

		// randomize chance of player making first move
		firstMove = rand() % 2 + 1;

		if (firstMove == 1)
		{
			std::cout << "Player 1 has the first move!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Player 2 has first move!" << std::endl << std::endl;
		}

		if (firstMove == 1)
		{
			while ((player1_Win == false) && (player2_Win == false))
			{
				std::cout << "Player 1 " << player1->get_Type() << " attacks!" << std::endl;
				attack_Pwr = player1->attack();
				player2->defend(attack_Pwr);
				player1_Win = player2->defeated();

				if (player1_Win == false)
				{
					std::cout << "Player 2 " << player2->get_Type() << " attacks!" << std::endl;
					attack_Pwr = player2->attack();
					player1->defend(attack_Pwr);
					player2_Win = player1->defeated();
				}
			}
		}
		else
		{
			while ((player1_Win == false) && (player2_Win == false))
			{
				std::cout << "Player 2 " << player2->get_Type() << " attacks!" << std::endl;
				attack_Pwr = player2->attack();
				player1->defend(attack_Pwr);
				player2_Win = player1->defeated();

				if (player2_Win == false)
				{
					std::cout << "Player 1 " << player1->get_Type() << " attacks!" << std::endl;
					attack_Pwr = player1->attack();
					player2->defend(attack_Pwr);
					player1_Win = player2->defeated();
				}
			}
		}

		// prompts for printing winner of the game
		if (player1_Win == true)
		{
			std::cout << "Player 1 " << player1->get_Type() << " is the winner!!!" << std::endl << std::endl;
		}
		else
		{
			std::cout << "Player 2 " << player2->get_Type() << " is the winner!!!" << std::endl << std::endl;
		}

		std::cout << "Would you like to play again?" << std::endl;
		std::cout << "1: Restart" << std::endl;
		std::cout << "2: Exit" << std::endl << std::endl;

		std::cin >> play_Again;

		while ((play_Again != 1) && (play_Again != 2))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "Invalid. Please enter a valid choice: ";
			std::cin >> play_Again;
		}

		switch (play_Again)
		{
		case 1:
		{
			std::cout << "Restarting." << std::endl << std::endl;
			game_End = false;
			player1_Win = false;
			player2_Win = false;
			break;
		}

		case 2:
		{
			std::cout << "Exiting." << std::endl << std::endl;
			game_End = true;
			break;
		}
		}
	} while (game_End == false);

	return 0;
}