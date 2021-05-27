

#include <string>
#include <vector>
#include <array>
#include "Shabloni.h"

class Board_Checkers;
class Movement;

class Cell
{
private:
	int x, y;
	void becomeDamka() { 
		isDamka = true; 
	}
	all_moves_vector make_attack_vector(const Board_Checkers& Board_Checkers, const pointer_to_move previous) const;
		
public:
	bool isDamka = false;
    const bool isWhite;
	Cell(int x, int y, bool isWhite) : x(x), y(y), isWhite(isWhite) {};
	coordinates getCoordinates() const {
		coordinates coords;
		coords[0] = this->x;
		coords[1] = this->y;
		return coords;
	}

	void makeMoveTo(int x, int y)
	{
		this->x = x; this->y = y;
	}
	
	void Damka_Check(const Board_Checkers& Board_Checkers);
	all_moves_vector make_move_vector(const Board_Checkers& Board_Checkers) const;
	std::string getLetter() const;
};
		
