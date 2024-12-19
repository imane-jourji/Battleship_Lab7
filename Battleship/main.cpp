/*
	Imane Jourji
	Computer Science Fall 2024
	Due: 12/17/2024
	Lab Name : Lab 7 Battleship
	Description : Make a simple battleship game
*/

#include "Game.h"
#include <iostream>

using namespace std;

int main() {

	//Game start object
	Game game;
	cout << "Welcome to Battleship" << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;

	bool InputActive;
	int choice;

	InputActive = true;

	//While loop to keep menu active

	while (InputActive)
	{
		cout << "Please input your choice ";
		cin >> choice;
		cout << endl;

		if (cin.fail() || choice < 1 || choice > 2)
		{
			cout << "Invalid Input please try again" << endl;

			cin.clear();
			cin.ignore(10000, '\n');
		}
		else
		{
			switch (choice)
			{
			case 1:
				game.startGame();
				break;
			case 2:
				return 0;
				break;
			default:
				break;
			}
		}
	}

}
