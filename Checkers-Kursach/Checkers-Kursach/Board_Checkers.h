#pragma once

#include <array>
//#include "Shabloni.h"

class Cell;
class Movement;

typedef std::array<int, 2> coordinates;
typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;

class Board_Checkers
{
public:
	const static int size = 8;
	Board_Checkers();

	Board_Checkers(const Board_Checkers& board_checkers);

	Cell* getColor(int x, int y) const {
		return this->boardMatrix[y][x];
	}

	Cell* getColor(int position) const {
		coordinates coords = getCoordinatesFromPosition(position);
		return getColor(coords[0], coords[1]);
	}
	Cell* boardMatrix[size][size];
	void make_steps(pointer_to_move move_p, Cell* cell);
private:
	

	coordinates getCoordinatesFromPosition(int position) const {
		coordinates coords;
		coords[0] = position % size;
		coords[1] = position / size;
		return coords;
	}

	int getPositionFromCoordinates(int x, int y) const {
		int res = size * y + x;
		return res;
	}

	void setColor(int position, Cell* cell)
	{
		coordinates coords = getCoordinatesFromPosition(position); // convert position to coordinates and use that
		setColor(coords[0], coords[1], cell);
	}

	void setColor(int x, int y, Cell* cell) {
		this->boardMatrix[y][x] = cell;
	}
};

