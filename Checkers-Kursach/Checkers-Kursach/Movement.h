#pragma once
#include <array>
#include <vector>
//#include "Shabloni.h"

class Cell;
class Board_Ckeckers;


typedef std::shared_ptr<Movement> pointer_to_move;
typedef std::array<int, 2> coordinates;
typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;

class Movement
{
private:
	const int x1;
	const int x2;
	const int y1;
	const int y2;
	
	const pointer_to_move previous;
	const bool multipleMove;

public:
	Movement(int x1, int y1, int x2, int y2, const pointer_to_move previous, bool multipleMove) : 
		x1(x1), y1(y1), x2(x2), y2(y2), previous(previous), multipleMove(multipleMove) {};

	coordinates get_Start() const;
	coordinates get_Finish() const;

	std::vector<Cell*> getJumpedPieces(const Board_Checkers& board) const;
	

};

