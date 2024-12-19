#ifndef GAME_H
#define GAME_H

class Game
{
public:
	Game();
	~Game();

	void startGame();
	void playerTurn();
	void ComputerTurn();
	void restart();

	bool checkWin();

	void printPlayerAttackBoard();


private:
	bool playerWin = false;
	bool ComputerWin = false;
	bool TurnActive = true;
	bool quit = false;

	int ComputerHitsLeft = 17;
	int PlayerHitsLeft = 17;

};

#endif // !GAME_H
