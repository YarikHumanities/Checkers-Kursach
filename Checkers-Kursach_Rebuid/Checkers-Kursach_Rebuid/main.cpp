#include "Cell.h"
#include "Movement.h"
#include "Computer.h"
#include "HumanPlayer.h"
#include "Board_Checkers.h"
#include <vector>
#include <iostream>

using namespace std;

bool isPlayer1 = true;
//bool endGameNow = false;
bool endGame(const Board_Checkers& Board_Checkers);
bool askIfTwoPlayer();






int main()
{
	Board_Checkers Board_Checkers;


	HumanPlayer* player3 = new HumanPlayer(true);
	HumanPlayer* player4 = new HumanPlayer(false);
	AIPlayer* player5 = new AIPlayer(false);

	bool check;
	check = askIfTwoPlayer();
	if (check)
	{
		delete player5;
	}
	else
	{
		delete player4;
	}
	system("CLS");

	if (check) {

		while (!endGame(Board_Checkers))
		{
			if (isPlayer1)
			{
				player3->getMovement(Board_Checkers);
			}
			else
			{
				player4->getMovement(Board_Checkers);
			}


			isPlayer1 = !isPlayer1;
		}
	}

	else {

		while (!endGame(Board_Checkers))
		{
			if (isPlayer1)
			{
				player3->getMovement(Board_Checkers);
			}
			else
			{
				player5->getMovement(Board_Checkers);
			}


			isPlayer1 = !isPlayer1;
		}
	}
}


bool askIfTwoPlayer()
{

	while (true)
	{
		//using namespace std;

		system("CLS");
		cout << "Start" << endl;
		cout << "Game with computer (1), game 1v1 (2), exit - 'exit'" << endl;

		string num;
		getline(cin, num);


		if (num == "1") {
			return false;
		}
		else if (num == "2") {
			return true;
		}

	
	}
}
bool endGame(const Board_Checkers& Board_Checkers)
{



		int movableWhiteNum = 0;
		int movableBlackNum = 0;

		for (int pos = 0; pos < Board_Checkers::size * Board_Checkers::size; pos++)
		{
			Cell* pieceHere = Board_Checkers.getColor(pos);
			if (pieceHere != nullptr)
			{

				if (!pieceHere->make_move_vector(Board_Checkers).empty())
				{
					if (pieceHere->isWhite)
						movableWhiteNum++;
					else
						movableBlackNum++;
				}
			}
		}

		//using namespace std;


		if (movableWhiteNum + movableBlackNum == 0) {
			cout << "Tie" << endl;
		}
		else if (movableWhiteNum == 0) {
			cout << "Black won" << endl;
		}
		else if (movableBlackNum == 0) {
			cout << "White won" << endl;
		}
		else {
			return false;
		}


		return true;
	
}