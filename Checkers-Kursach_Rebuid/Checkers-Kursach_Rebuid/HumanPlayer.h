
#include "Shabloni.h"

class Board_Checkers;
class Movement;
class Cell;

#include <vector>
#include <string>

class HumanPlayer
{
private:
	const bool isWhite;	
	
	Cell* get_coodr_from(const Board_Checkers& Board_Checkers);
	pointer_to_move get_move_from(const all_moves_vector possibleMovements);
	void print_board(const Board_Checkers& Board_Checkers, const all_moves_vector possibleMovements);
	void print_board(const Board_Checkers& Board_Checkers);
	std::string getColor();
public:
	HumanPlayer(bool isWhite) : isWhite(isWhite) {};
	void getMovement(Board_Checkers& Board_Checkers);
};


