#pragma once
#include "Board_Checkers.h"
#include "Cell.h"
#include "Shabloni.h"
#include <vector>
#include <utility>
class Cell;
class Board_Ckeckers;

class Movement
{
private:
	const int x1;
	const int x2;
	const int y1;
	const int y2;
	const bool multipleMove;
public:
	Movement(int x1, int y1, int x2, int y2, bool multipleMove) : x1(x1), y1(y1), x2(x2), y2(y2), multipleMove(multipleMove) {};
	coordinates get_Start() const;
	coordinates get_Finish() const;
	std::pair<coordinates, coordinates> make_move_vector(int x1, int y1, int x2, int y2, Board_Checkers& board_checkers) const;

};

