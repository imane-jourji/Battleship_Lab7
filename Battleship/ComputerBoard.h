#ifndef COMPUTERBOARD_H
#define COMPUTERBOARD_H

extern char computerBoard[10][10]; // Declare the global variable

class ComputerBoard
{
public:
	
	ComputerBoard();
	~ComputerBoard();

	void setBoard();
	void printBoard();

	bool isValidPlacement(int size, int direction, int x, int y);
	void placeShip(int size, int direction, int x, int y);

	void setAttackBoard(char Attack_Board[10][10]);
	bool checkHit(int x, int y);


	void AddShips();
	int shipSize(int shipNumber);

private:
	int shipsAdded = 0;
	bool placingShip = true;

	char EnemyBoard[10][10];

};

#endif //COMPUTERBOARD_H
