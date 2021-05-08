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
	all_moves_vector moves(0);
	int y_start;
	int y_iterator;
	int x_quant;
	bool check = false;

	if (isWhite) {
		y_start = this->y + 1;
		y_iterator = -2;
	}
	if (!isWhite) {
		y_start = this->y - 1;
		y_iterator = 2;
	}
	x_quant = 1;
	if (this->isDamka) {
		x_quant = 2;
	}
	for (int i = this->x-1; i < this->x+1; i+=2)
	{
		int y = y_start - y_iterator;
		if ((x < 0 || x >= board_checkers.size || y < 0 || y >= board_checkers.size)) {
			continue;
		}
		if (board_checkers.getColor(x, y) == nullptr) {
			//можно пушить мувмент в вектор
		}
	}

}
