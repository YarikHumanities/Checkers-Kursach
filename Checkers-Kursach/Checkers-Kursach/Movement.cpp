#include "Movement.h"
#include "Board_Checkers.h"
#include "Cell.h"
#include "Shabloni.h"
#include <vector>
coordinates Movement::get_Start() const {
	coordinates start_placing;
	start_placing[0] = this->x1;
	start_placing[1] = this->y1;
	return start_placing;
}
coordinates Movement::get_Finish() const {
	coordinates end_placing;
	end_placing[0] = this->x2;
	end_placing[1] = this->y2;
	return end_placing;
}
std::pair<coordinates, coordinates> Movement::make_move_vector(int x1, int y1, int x2, int y2, Board_Checkers& board_checkers) const {
	std::pair<coordinates, coordinates> move;
	bool check = false;
	if (x2==x1+1 && (y2==y1+1 || y2==y1-1)) {
		bool ckeck = true;
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
