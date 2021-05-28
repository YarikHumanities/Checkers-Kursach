#include "Board_Checkers.h"

#include "Cell.h"
#include "Movement.h"
#include "Shabloni.h"

Board_Checkers::Board_Checkers()
{
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            
            if (y < 3 && right_place(x, y))
            {
                setColor(x, y, new Cell(x, y, true));
            }
            
            else if (y >= size - 3 && right_place(x, y))
            {
				setColor(x, y, new Cell(x, y, false));
            }
            
            else
            {
            	setColor(x, y, nullptr);
            }
        }
    }
}

Board_Checkers::Board_Checkers(const Board_Checkers& Board_Checkers)
{
	for (int pos = 0; pos < size * size; pos++)
    {
		setColor(pos, Board_Checkers.getColor(pos));  
    }
}

void Board_Checkers::setColor(int position, Cell* piece)
{
    coordinates coords = getCoordsFromPos(position);
    setColor(coords[0], coords[1], piece);
}

Cell* Board_Checkers::getColor(int position) const
{
    coordinates coords = getCoordsFromPos(position);
    return getColor(coords[0], coords[1]);
}

coordinates Board_Checkers::getCoordsFromPos(int position) const
{
    coordinates coords;
    coords[0] = position % size;
    coords[1] = position / size;
    return coords;
}

bool Board_Checkers::boundsCheck(int x, int y) const
{
    return (x < 0 || x >= size ||
        y < 0 || y >= size);
}

bool Board_Checkers::boundsCheck(int position) const
{
    coordinates coords = getCoordsFromPos(position);
    return boundsCheck(coords[0], coords[1]);
}



void Board_Checkers::make_steps(const pointer_to_move Movement, Cell* piece)
{
    coordinates MovementStartingPos = piece->getCoordinates();
    coordinates MovementEndingPos = Movement->get_Finish();
    
    // find any pieces we've jumped in the process, and reMovement them as well
    std::vector<Cell*> attacked = Movement->get_attacked_cell(*this);
    if (!attacked.empty())
    {
        // loop over all jumped pieces and reMovement them
        for (unsigned int i = 0; i < attacked.size(); i++)
        {
            if (attacked[i] != nullptr)
            {
                setColor(attacked[i]->getCoordinates()[0], 
                			attacked[i]->getCoordinates()[1], nullptr);
            }
        }
    }
    setColor(MovementStartingPos[0], MovementStartingPos[1], nullptr);
    piece->makeMoveTo(MovementEndingPos[0], MovementEndingPos[1]);
    piece->Damka_Check(*this);
    setColor(MovementEndingPos[0], MovementEndingPos[1], piece);
}
