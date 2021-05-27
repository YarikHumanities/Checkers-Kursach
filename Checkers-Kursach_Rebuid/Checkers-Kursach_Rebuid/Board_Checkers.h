

#include <array>
#include "Shabloni.h"

class Cell;
class Movement;
	
class Board_Checkers
{
public:
    const static int size = 8;
	Board_Checkers();
	Board_Checkers(const Board_Checkers& Board_Checkers);
	Cell* getColor(int x, int y) const { return this->boardMatrix[y][x]; }
	Cell* getColor(int position) const;
	int getPositionFromCoordinates(int x, int y) const {
		return size * y + x;
	}
	bool right_place(int x, int y) const {
		if (x % 2 == 0 && y%2==0) {
			return true;
		}
		if (x % 2 != 0 && y % 2 != 0) {
			return true;
		}
		return false;
		
	}
	void make_steps(const pointer_to_move Movement, Cell* piece);
	bool boundsCheck(int x, int y) const;
	bool boundsCheck(int position) const;
		
private:
    Cell* boardMatrix[size][size];
	void setColor(int x, int y, Cell* piece) 
	{ 
		this->boardMatrix[y][x] = piece; 
	}
	void setColor(int position, Cell* piece);
	coordinates getCoordsFromPos(int position) const;
};


