#include "Game.h"
#include <iostream>
#include "PlayerBoard.h"
#include "ComputerBoard.h"
#include <iomanip>


using namespace std;

char computerBoard[10][10];
char playerBoard[10][10];

PlayerBoard Player;
ComputerBoard Computer;

Game::Game()
{
	//Set the board to all ~
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			computerBoard[i][j] = '~';
		}
	}
}

Game::~Game()
{
}

void Game::startGame()
{

	playerWin = false;
	ComputerWin = false;

	//Add ships to the board
	Player.AddShips();
	Player.printBoard();
	Computer.AddShips();

	while (!checkWin())
	{
		playerTurn();
	}
}

//Player turn function
void Game::playerTurn()
{
	bool choiceActive = true;
	while (choiceActive)
	{
		cout << "Would you like to surrender? (y/n) ";
		char choice;
		cin >> choice;
		if (choice == 'y')
		{
			ComputerWin = true;
			cout << "Computer Wins!" << endl;
			restart();
			return;
		}
		else if (choice == 'n')
		{
			choiceActive = false;
		}
		else
		{
			cout << "Invalid input please try again" << endl;
		}
	}

	cout << "Players board" << endl;
	Player.printBoard();

	cout << "Player's Turn" << endl;
	printPlayerAttackBoard();

	int x = -1 , y = -1;
	char comma;
	while (true) {
		cout << "Enter the x,y coordinates you would like to attack (x,y) : ";
		cin >> y >> comma >> x;

		if (cin.fail() || x < 1 || x > 10 || y < 1 || y > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid coordinates, try again" << endl;
		}
		else
		{
			break;
		}
	}
	if (Computer.checkHit(x - 1, y - 1))
	{
		cout << "Hit!" << endl;
		computerBoard[x - 1][y - 1] = 'H';
		ComputerHitsLeft--;
	}
	else
	{
		cout << "Miss!" << endl;
		computerBoard[x - 1][y - 1] = 'M';
	}
	if (!checkWin()) {
		cout << "Computer's Turn" << endl;
		ComputerTurn();
	}
}
		
void Game::ComputerTurn() {
	cout << "Computer's Turn" << endl;

	bool turnActive = true; // Ensures computer keeps generating until a valid move is made
	while (turnActive) {
		int x = rand() % 10; // Randomly generate x-coordinate (0-9)
		int y = rand() % 10; // Randomly generate y-coordinate (0-9)

		// Check if this position has already been attacked
		if (Player.checkIfAlreadyHit(x, y)) {
			// If already attacked, continue the loop to generate new coordinates
			continue;
		}
		else {
			// If not already attacked, check for hit or miss
			if (Player.checkHit(x, y)) {
				cout << "Computer Hit!" << endl;
				Player.changePlayerBoard(x, y, 'H'); // Update player's board with 'H' for hit
				PlayerHitsLeft--; // Decrement player hits left
			}
			else {
				cout << "Computer Miss!" << endl;
				Player.changePlayerBoard(x, y, 'M'); // Update player's board with 'M' for miss
			}

			// Print the updated player's board
			Player.printBoard();

			// Exit the loop since a valid move was made
			turnActive = false;
		}
	}
}


//Restart function
void Game::restart()
{
	char choice;
	choice = 'f';
	while (choice != 'y' && choice != 'n')
	{
		cout << "Would You like to play again? (y/n)   ";
		cin >> choice;
		cout << endl;
		if (cin.fail())
		{
			cout << "Invalid input please try again" << endl;
			choice = 'f';
		}
	}

	switch (choice)
	{
	default:
		break;
	case 'y':

		Player.setBoard();
		Computer.setBoard();
		PlayerHitsLeft = 17;
		ComputerHitsLeft = 17;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				computerBoard[i][j] = '~';
			}
		}

		startGame();
		break;
	case 'n':
		quit = true;
		break;
	}
}

//Check win function
bool Game::checkWin()
{
	if (ComputerHitsLeft == 0)
	{
		playerWin = true;
		cout << "Player Wins!" << endl;
		restart();
		return true;
	}
	else if (PlayerHitsLeft == 0)
	{
		ComputerWin = true;
		cout << "Computer Wins!" << endl;
		restart();
		return true;
	}
	else
	{
		return false;
	}
}


//Print player attack board
void Game::printPlayerAttackBoard()
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