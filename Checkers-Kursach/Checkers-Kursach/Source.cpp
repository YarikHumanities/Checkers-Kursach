#include <iostream>
#include "Board_Checkers.h"
#include "Cell.h"
#include "Movement.h"
#include "Player.h"
#include "Shabloni.h"
#include <vector>
#include <iostream>
bool isPlayer1 = true;

bool game_finish(const Board_Checkers board_checkers) {
	int whiteQuant = 0;
	int blackQuant = 0;
	for (int pos = 0; pos < Board_Checkers::size*Board_Checkers::size; pos++)
	{
		Cell* current = board_checkers.getColor(pos);
		if (current == nullptr) {
			if (!current->make_move_vector(board_checkers).empty()) {
				if (current->isWhite) {
					whiteQuant++;
				}
				else {
					blackQuant++;
				}
			}
		}

	}


	if (whiteQuant + blackQuant == 0) {
		std::cout << "Tie" << std::endl;
	}
	else if (whiteQuant == 0) {
		std::cout << "Black won" << std::endl;
	}
	else if (blackQuant == 0) {
		std::cout << "White won" << std::endl;
	}
	else {
		return false;
	}
	return true;

}

int main() {
	Board_Checkers board_checkers;
	Player* player1;
	Player* player2;
	while (!game_finish(board_checkers)) {
		if (isPlayer1) {
			player1->form_move(board_checkers);
		}
		else {
			player2->form_move(board_checkers);
		}

		isPlayer1 = !isPlayer1;
	}


}