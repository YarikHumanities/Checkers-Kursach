#include "Computer.h"

#include "Board_Checkers.h"
#include "Cell.h"
#include "Movement.h"
#include "Shabloni.h"

#include <unordered_map>
#include <vector>
#include <cstdlib>

typedef unordered_map<Cell*, all_moves_vector> moveVars;
typedef unordered_map<pointer_to_move, Cell*> chosenMoves; 




void AIPlayer::getMovement(Board_Checkers& Board_Checkers)
{
    using namespace std;


    //просто проходка по всем нашим ячейкам

    moveVars possible;


    for (int x = 0; x < Board_Checkers::size; x++)
    {
        for (int y = 0; y < Board_Checkers::size; y++)
        {

            Cell* curCell = Board_Checkers.getColor(x, y);
            if (curCell != nullptr && curCell->isWhite == this->isWhite)
            {

                all_moves_vector possibleMovements = curCell->make_move_vector(Board_Checkers);


                if (!possibleMovements.empty())
                    possible[curCell] = possibleMovements;
            }
        }
    }




    Cell* furthestBackwardPiece = possible.begin()->first;
    Cell* furthestForwardPiece = possible.begin()->first;


    chosenMoves best_move_for_each_cell;

    //проходка по всем элементам мапы
    for (auto it : possible)
    {
        Cell* piece = it.first;


        int thisPieceY = piece->getCoordinates()[1];

        if (thisPieceY > furthestForwardPiece->getCoordinates()[1])
        {

            if (isWhite) {
                furthestForwardPiece = piece;
            }

            else {
                furthestBackwardPiece = piece;
            }
        }

        if (thisPieceY < furthestBackwardPiece->getCoordinates()[1])
        {
            if (isWhite) {
                furthestBackwardPiece = piece;
            }

            else {
                furthestForwardPiece = piece;
            }
        }



        //тут мы будем искать у какой ячейки может быть выполнен ход с самым большим количевством сьеденых вражеских шашек

        all_moves_vector possibleMovements = possible[piece];
        pointer_to_move maxJumpMovement = possibleMovements[0];
        int maxJumpMovementLength = 0;
        for (int i = 0; i < possibleMovements.size(); i++)
        {

            vector<Cell*> attacked = possibleMovements[i]->get_attacked_cell(Board_Checkers);


            if (!attacked.empty())
            {
                int jumpLength = attacked.size();


                if (jumpLength >= maxJumpMovementLength)
                {
                    maxJumpMovementLength = jumpLength;
                    maxJumpMovement = possibleMovements[i];
                }
            }
        }



        //теперь пушим в вектор наш самый удачный вариант который в перспективе сьест больше всего шашек
        best_move_for_each_cell[maxJumpMovement] = piece;
    }

}
