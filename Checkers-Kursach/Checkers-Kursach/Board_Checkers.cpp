#include "Board_Checkers.h"
#include "Cell.h"
#include "Movement.h"
//#include "Shabloni.h"

typedef std::array<int, 2> coordinates;
typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;

Board_Checkers::Board_Checkers() {
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (y < 3 && (x % 2 == y % 2)) {
				setColor(x, y, new Cell(x, y, true));
			}
			else if (y >= size - 3 && (x % 2 == y % 2)) {
				setColor(x, y, new Cell(x, y, false));
			}
			else {
				setColor(x, y, nullptr);
			}
		}
	}
}
Board_Checkers::Board_Checkers(const Board_Checkers& board_checkers) {
	for (int position = 0; position < size*size; position++)
	{
		setColor(position, board_checkers.getColor(position));

	}
}
void Board_Checkers::make_steps(pointer_to_move move_p, Cell* cell) {
	coordinates start_position = cell->getCoordinates();
	coordinates end_position = move_p->get_Finish();
	setColor(start_position[0], start_position[1], nullptr);
	cell->makeMoveTo(end_position[0], end_position[1]);
	setColor(end_position[0], end_position[1], cell);
}