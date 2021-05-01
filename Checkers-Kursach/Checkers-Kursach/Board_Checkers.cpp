#include "Board_Checkers.h"
#include "Cell.h"
Board_Checkers::Board_Checkers() {
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			if (y < 3) {
				setColor(x, y, new Cell(x, y, true));
			}
			else if (y >= size - 3) {
				setColor(x, y, new Cell(x, y, false));
			}
			else {
				setColor(x, y, nullptr);
			}
		}
	}
}