#pragma once
#include "Cell.h"
class Board_Checkers
{
public:
	const static int size = 8;
	Board_Checkers();
	void setColor() {
		
	}
private:
	Cell* boardMatrix[size][size];
	void setColor(int x, int y, Cell* cell) {
		this->boardMatrix[y][x] = cell;
	}
};

