#include "Cell.h"
#include "Shabloni.h"
#include "Board_Checkers.h"
#include <iostream>


coordinates Cell::getCoordinates() const {
	coordinates coords;
	coords[0] = this->x;
	coords[1] = this->y;
	return coords;
}
void Cell::DamkaCheck(const Board_Checkers& board_checkers) {                        //every move this function must be called to check
	if (isWhite && this->y == Board_Checkers::size - 1 || !isWhite && this->y == 0) {
		becomeDamka();
	}
}
std::string Cell::getLetter() const {
	std::string letter;
	if (isWhite == true) {
		letter = "W";
	}
	else {
		letter = "B";
	}
	if (isDamka == true) {
		letter += "Dam";
	}
	else {
		letter += " ";
	}
	return letter;
}
all_moves_vector Cell::make_move_vector(int x1, int y1, int x2, int y2, const Board_Checkers& board_checkers) const {
	std::pair<coordinates, coordinates> move;
	bool check = false;
	if (isWhite) {
		if ((x2 == x1 + 1 && (y2 == y1 + 1 || y2 == y1 - 1)) && board_checkers.getColor(x2, y2)==nullptr) {
			bool ckeck = true;
		}
	}
	if (!isWhite) {
		if ((x2 == x1 - 1 && (y2 == y1 + 1 || y2 == y1 - 1)) && board_checkers.getColor(x2, y2) == nullptr) {
			bool check = true;
		}
	}
	if (check == true) {
		coordinates start;
		start[0] = x1;
		start[1] = y1;
		coordinates finish;
		finish[0] = x2;
		finish[1] = y2;
		move.first = start;
		move.second = finish;

		return move;
	}
}
