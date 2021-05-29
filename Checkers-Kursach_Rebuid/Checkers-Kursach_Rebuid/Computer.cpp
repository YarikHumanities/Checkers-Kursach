#include <unordered_map>
#include <vector>
#include <cstdlib>
#include "Computer.h"

#include "Board_Checkers.h"
#include "Cell.h"
#include "Movement.h"

#include "Shabloni.h"


typedef unordered_map<Cell*, all_moves_vector> moveVars;
typedef unordered_map<pointer_to_move, Cell*> chosenMoves; 
int random = rand() & 100;
template <class T, class E>

T Computer::getKeyByValue(std::unordered_map<T, E> map, E value)
{
    for (auto it : map)
    {
        if (it.second == value)
        {
            return it.first;
        }
    }
    return nullptr;
}

void Computer::getMovement(Board_Checkers& Board_Checkers)
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


     //
        //мб что-то добавить
     //

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





    pointer_to_move finalMove = best_move_for_each_cell.begin()->first;
    int finalMove_attackL = 0;
    for (auto it : best_move_for_each_cell)
    {
        pointer_to_move Movement = it.first;

       
        vector<Cell*> attacked = Movement->get_attacked_cell(Board_Checkers);

        
        if (!attacked.empty())
        {
            int current_best_attack = attacked.size();

           
            if (current_best_attack >= finalMove_attackL)
            {
                finalMove_attackL = current_best_attack;
                finalMove = Movement;
            }
        }
    }

    
    if (finalMove_attackL > 0)
    {
        Board_Checkers.make_steps(finalMove, best_move_for_each_cell[finalMove]);
    }
    else 
    {
        int randomNum = rand() & 100;
        if (randomNum >= 50)
        {
            
            Board_Checkers.make_steps(getKeyByValue(best_move_for_each_cell, furthestBackwardPiece), furthestBackwardPiece);
        }
        else
        {
            Board_Checkers.make_steps(getKeyByValue(best_move_for_each_cell, furthestForwardPiece), furthestForwardPiece);
        }
    }
}




