#include "Board_Checkers.h"
#include "Cell.h"
#include "Shabloni.h"
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