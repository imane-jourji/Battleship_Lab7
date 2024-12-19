#include "ComputerBoard.h"
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

ComputerBoard::ComputerBoard()
{
	setBoard();
}

ComputerBoard::~ComputerBoard()
{
}
//Sets the board to all ~
void ComputerBoard::setBoard()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			computerBoard[i][j] = '~';
		}
	}
}
//Prints the board
void ComputerBoard::printBoard()
{
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << i + 1;
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		if (i < 9) {
			cout << i + 1 << " ";
			cout << setw(2);
			for (int j = 0; j < 10; j++)
			{

				cout << computerBoard[i][j] << " ";
			}
			cout << endl;
		}
		else
		{
			cout << i + 1 << " ";
			for (int j = 0; j < 10; j++)
			{
				cout << computerBoard[i][j] << " ";
			}
			cout << endl;
		}
	}
}
//Checks if the ship can be placed on the board
bool ComputerBoard::isValidPlacement(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	bool validPlacement = true;
	int i = size;

	while (i != 0 && validPlacement)
	{
		if (y < 0 || y >= 10 || x < 0 || x >= 10) {
			validPlacement = false;
			break;
		}

		if (computerBoard[y][x] == '~') {

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
			i--;
		}
		else {
			validPlacement = false;
		}
	}
	return validPlacement;
}
//Places the ship on the board
void ComputerBoard::placeShip(int size, int direction, int x, int y)
{
	x = x - 1;
	y = y - 1;
	int i = size;
	while (i != 0)
	{
		// Check if the position is within bounds before placing
		if (y < 0 || y >= 10 || x < 0 || x >= 10) {
			// If out of bounds, return immediately without placing
			return;
		}
		
		// Place the ship part on the board
		computerBoard[y][x] = '#';
		
		// Move to the next cell based on the direction
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
		
		// Decrement the ship size counter
		i--;
	}
}

void ComputerBoard::setAttackBoard(char Attack_Board[10][10])
{
}

//Checks if the player hit a ship
bool ComputerBoard::checkHit(int x, int y)
{
	// Check if the coordinates are within the bounds of the board
	if (x < 0 || x >= 10 || y < 0 || y >= 10) {
		// Out of bounds, return false (miss)
		return false;
	}
	
	// Check if the cell contains a ship ('#')
	if (computerBoard[y][x] == '#')
	{
		computerBoard[y][x] = 'H';          // Mark the hit ('H')
		return true;                  // Return true for a successful hit
	}
	else
	{
		computerBoard[y][x] = 'M';          // Mark the miss ('M')
		return false;                 // Return false for a miss
	}
}


//Places ships on the board
void ComputerBoard::AddShips()
{
	srand(static_cast<unsigned int>(time(0)));
	int x, y, direction;

	for (int i = 0; i < 5; i++)
	{
		bool placed = false;
		while (!placed)
		{
			x = rand() % 10 + 1;
			y = rand() % 10 + 1;
			direction = rand() % 4 + 1;
			
			if (isValidPlacement(shipSize(i), direction, x, y))
			{
				placeShip(shipSize(i), direction, x, y);
				placed = true;
			}
		}	
	}
}


int ComputerBoard::shipSize(int shipNumber)
{
	int size;
	switch (shipNumber)
	{
	case 0: // First ship (Size 5)
		size = 5;
		break;
	case 1: // Second ship (Size 4)
		size = 4;
		break;
	case 2: // Third ship (Size 3)
		size = 3;
		break;
	case 3: // Fourth ship (Size 3)
		size = 3;
		break;
	case 4: // Fifth ship (Size 2)
		size = 2;
		break;
	default:
		size = 0; // In case of an invalid shipNumber
		break;
	}
	return size;
}