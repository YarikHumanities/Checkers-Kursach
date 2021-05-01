#pragma once
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

};

