#ifndef PLAYERBOARD_H_INCLUDED
#define PLAYERBOARD_H_INCLUDED
#include <limits>      // Required for std::numeric_limits

extern char playerBoard[10][10]; // Declare the global variable

class PlayerBoard
{
	public:

		PlayerBoard();               // Constructor
		~PlayerBoard();              // Destructor
	     
		void setBoard();            // Initialize the board to default state    
		void printBoard();          // Print the current board

		    // Initialize the attack board
		bool isValidPlacement(int size, int direction, int x, int y);    // Validate ship placement
		void placeShip(int size, int direction, int x, int y);      // Place a ship on the board


		void setAttackBoard(char Attack_Board[10][10]);  // Initialize the attack board
		bool checkHit(int x, int y);          // Check if the attack is a hit or miss
	
		bool checkIfAlreadyHit(int x, int y);   // Check if a cell has already been attacked
		void changePlayerBoard(int x, int y, char c);    // Update a specific cell on the board



		void AddShips();               // Add all ships to the board
		int shipSize(int shipNumber);   // Get the size of a specific ship

		bool placeSingleShip(int shipIndex, int& x, int& y, int& direction); // Handle single ship placement

	private:

		int shipsAdded = 0;          // Number of ships added to the board
	
};

#endif //PLAYERBOARD_H_INCLUDED