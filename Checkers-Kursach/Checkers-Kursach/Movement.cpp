
#include "Movement.h"

#include "Cell.h"
#include "Board_Checkers.h"
#include "Shabloni.h"

//typedef std::shared_ptr<Movement> pointer_to_move;
//typedef std::array<int, 2> coordinates;
//typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;

coordinates Movement::get_Start() const {
	coordinates start_placing;
	start_placing[0] = this->x1;
	start_placing[1] = this->y1;
	return start_placing;
}
coordinates Movement::get_Finish() const {
	coordinates end_placing;
	end_placing[0] = this->x2;
	end_placing[1] = this->y2;
	return end_placing;
}

std::vector<Cell*> Movement::getJumpedPieces(const Board_Checkers& board) const
{
    
    std::vector<Cell*> pieces(0);

   
    if (multipleMove)
    {
        
        int pieceX = (x1 + x2) / 2;
        int pieceY = (y1 + y2) / 2;


        pieces.push_back(board.getColor(pieceX, pieceY));

      
        if (previous != nullptr)
        {
            
            std::vector<Cell*> prevJumped = previous->getJumpedPieces(board);
            pieces.insert(pieces.end(), prevJumped.begin(), prevJumped.end());

            
        }
    }

   
    pieces.shrink_to_fit();
    return pieces;
}
