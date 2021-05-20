#include "Movement.h"
#include "Board_Checkers.h"
#include "Cell.h"
#include "Shabloni.h"
#include <vector>
#include <memory>
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
std::vector<Cell*> Movement::get_attacked_cell(const Board_Checkers& board_checkers) const {
	std::vector<Cell*> attacked_cells(0);
	if (multipleMove) {
		int x_cell = (x1 + x2) / 2;
		int y_cell = (y1 + y2) / 2;
		attacked_cells.push_back(board_checkers.getColor(x_cell, y_cell));
		if (previous != nullptr) {
			std::vector<Cell*> previous_attack = previous->get_attacked_cell(board_checkers);
			attacked_cells.insert(attacked_cells.end(), previous_attack.begin(), previous_attack.end());
		}
	}
	attacked_cells.shrink_to_fit();
	return attacked_cells;
}
