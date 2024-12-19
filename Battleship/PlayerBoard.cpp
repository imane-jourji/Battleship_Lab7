#include "PlayerBoard.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

// Constructor to initialize the player board
PlayerBoard::PlayerBoard()
{
	setBoard();
}

// Destructor
PlayerBoard::~PlayerBoard()
{
}

//Sets the board to all ~
void PlayerBoard::setBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			playerBoard[i][j] = '~';
		}
	}
}


// Prints the player's board to the console
void PlayerBoard::printBoard()
{
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i + 1;
	}
	cout << endl;
	
	for (int i = 0; i < 10; i++)
	{
	
		cout << i + 1 << " ";
		
		for (int j = 0; j < 10; j++)
		{
			cout << playerBoard[i][j] << " ";
		}
		cout << endl;
	}
}
	


//Checks if the ship can be placed at the specified location
bool PlayerBoard::isValidPlacement(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	bool validPlacement = true;
	
	// Check the validity of all ship segments
	for (int i = 0; i < size; ++i) {
		if (x < 0 || x >= 10 || y < 0 || y >= 10 || playerBoard[y][x] != '~') {
			validPlacement = false;
			cout << "Invalid placement: Out of bounds or overlapping with another ship." << endl;
			return false;
		}

		switch (direction)
		{
		case 1: // Up
			y--;
			break;
		case 2: // Down
			y++;
			break;
		case 3: // Left
			x--;
			break;
		case 4: // Right
			x++;
			break;
		default:
			validPlacement = false;
			cout << "Error: Invalid direction." << endl;
			break;
		}
	}

	return validPlacement;
}

//Places the ship on the board
void PlayerBoard::placeShip(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	
	for (int i = 0; i < size; i++)
	{
		playerBoard[y][x] = '#';

		switch (direction)
		{
		case 1: // Up
			y--;
			break;
		case 2: // Down
			y++;
			break;
		case 3: // Left
			x--;
			break;
		case 4: // Right
			x++;
			break;
		}
	}
}

//Sets the attack board to all ~
void PlayerBoard::setAttackBoard(char Attack_Board[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Attack_Board[i][j] = '~';
		}
	}
}


//Checks if the attack is a hit or miss
bool PlayerBoard::checkHit(int x, int y)
{
	// Ensure that x and y are within bounds
	if (x < 0 || x >= 10 || y < 0 || y >= 10) {
		cout << "Invalid coordinates." << endl;
		return false;
	}
	
	if (playerBoard[y][x] == '#')
	{
		playerBoard[y][x] = 'H';
		return true;
	}
	else
	{
		playerBoard[y][x] = 'M';
		return false;
	}
}


//Checks if the attack has already been made at the specified location
bool PlayerBoard::checkIfAlreadyHit(int x, int y)
{
	// Ensure that x and y are within bounds
	if (x < 0 || x >= 10 || y < 0 || y >= 10) {
		cout << "Invalid coordinates." << endl;
		return true;  
	}
	return (playerBoard[y][x] == 'H' || playerBoard[y][x] == 'M');
}

//Changes the player board's board cell to the specified character
void PlayerBoard::changePlayerBoard(int x, int y, char c)
{
	playerBoard[y][x] = c;

}

// Handles the placement of a single ship with user input
bool PlayerBoard::placeSingleShip(int shipIndex, int& x, int& y, int& direction) {
	bool placingShip = true;
	while (placingShip) {
		cout << "Enter the coordinates for ship " << shipIndex + 1 << " (Size " << shipSize(shipIndex) << ") (x,y): ";
		cin >> x >> y;
		
		if (cin.fail() || x > 10 || x < 1 || y < 1 || y > 10) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter values between 1 and 10 for both x and y" << endl;
			continue;
		}
		else {
			cout << "What direction would you like the ship to face? (1 = Up, 2 = Down, 3 = Left, 4 = Right): ";
			cin >> direction;
			
			if (cin.fail() || direction > 4 || direction < 1) 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please enter a direction between 1 and 4." << endl;
				continue;
			}
			if (isValidPlacement(shipSize(shipIndex), direction, x, y)) 
			{
				placeShip(shipSize(shipIndex), direction, x, y);
				return true;
			}
			
		}
	}
	return false;
}


//Adds the ships to the board
void PlayerBoard::AddShips()
{
	bool placingShip = true;
	int x, y, direction;
	for (int i = 0; i < 5; i++)
	{
		printBoard();
		placingShip = true;

		if (placeSingleShip(i, x, y, direction))
		{
			placingShip = false;
		}
	}
}
				
//Returns the size of the ship
int PlayerBoard::shipSize(int shipNumber)
{
	int size;
	switch (shipNumber)
	{
	case 0:            // First ship (Size 5)
		size = 5;
		break;
	case 1:           // Second ship (Size 4)
		size = 4;
		break;
	case 2:            // Third ship (Size 3)
		size = 3;
		break;
	case 3:           // Fourth ship (Size 3)
		size = 3;
		break;
	case 4:            // Fifth ship (Size 2)
		size = 2;
		break;
	default:
		size = 0;       // In case of an invalid shipNumber
		break;
	}
	return size;
}