#include "Movement.h"

#include "Cell.h"
#include "Board_Checkers.h"
#include "Shabloni.h"

coordinates Movement::get_Start() const
{
    coordinates position;
    position[0] = x1;
    position[1] = y1;
    return position;
}

coordinates Movement::get_Finish() const
{
    coordinates position;
    position[0] = x2;
    position[1] = y2;
    return position;
}
    
std::vector<Cell*> Movement::get_attacked_cell(const Board_Checkers& Board_Checkers) const
{
    std::vector<Cell*> pieces(0);
    if (multipleMove)
    {
        int pieceX = (x1 + x2)/2;
        int pieceY = (y1 + y2)/2;
        pieces.push_back(Board_Checkers.getColor(pieceX, pieceY));
        if (previous != nullptr)
        {
            std::vector<Cell*> prevJumped = previous->get_attacked_cell(Board_Checkers);
            pieces.insert(pieces.end(), prevJumped.begin(), prevJumped.end()); 
        }
    }
    pieces.shrink_to_fit();
    return pieces;
}
