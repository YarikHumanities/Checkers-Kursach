#include "Cell.h"
#include "Shabloni.h"

coordinates Cell::getCoordinates() const {
	coordinates coords;
	coords[0] = this->x;
	coords[1] = this->y;
	return coords;
}
void Cell::DamkaCheck(const Board_Checkers& board_checkers) { //every move this function must be called to check
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
