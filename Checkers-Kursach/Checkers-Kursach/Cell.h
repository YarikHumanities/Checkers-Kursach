#pragma once
#include "Shabloni.h"
#include "Board_Checkers.h"
#include <iostream>
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
};

