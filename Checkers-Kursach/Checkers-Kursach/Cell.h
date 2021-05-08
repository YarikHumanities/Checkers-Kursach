#pragma once
#include "Shabloni.h"
#include "Board_Checkers.h"
#include <iostream>
#include <memory>
#include <vector>
//using namespace std;
class Board_Checkers;
class Movement;

typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;


class Cell
{
private:
	int x;
	int y;
	bool isDamka = false;
	void becomeDamka() {
		isDamka = true;
	}
public:
	const bool isWhite;
	Cell(int x, int y, bool isWhite): x(x), y(y), isWhite(isWhite){}
	coordinates getCoordinates() const;
	std::string getLetter() const;
	void DamkaCheck(const Board_Checkers& board_checkers);
	void makeMoveTo(int x, int y) {
		this->x = x;
		this->y = y;
	}
	all_moves_vector make_move_vector(int x1, int y1, int x2, int y2, const Board_Checkers& board_checkers) const;
};


