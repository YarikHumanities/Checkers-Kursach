#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Cell.h"
#include "Board_Checkers.h"
#include "Movement.h"
class Board_Checkers;
class Cell;
class Movement;

typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;

class Player
{
private:
	const bool isWhite;
	Cell* get_coodr_from(const Board_Checkers& board_checkers);
	pointer_to_move get_move_from(const all_moves_vector all_moves);
	void print_board(const Board_Checkers& board_checkers, const all_moves_vector all_moves);
	void print_board(const Board_Checkers& board_checkers);
	
public:
	Player(bool isWhite): isWhite(isWhite){}
	void form_move(Board_Checkers& board_checkers);
};

