#include "Cell.h"

#include "Board_Checkers.h"
#include "Movement.h"
#include "Shabloni.h"

#include <iostream>

 
all_moves_vector Cell::make_move_vector(const Board_Checkers& Board_Checkers) const
{
    all_moves_vector moves(0);
    int y_start; 
    int y_iterator;
    int x_quant;
    bool check = false;
    if (isWhite)
    {
        y_start = this->y + 1; 
        y_iterator = -2;
    }
    if(!isWhite)
    { 
        y_start = this->y - 1;
        y_iterator = 2;
    }
    x_quant = 1; 
    if (this->isDamka)
        x_quant = 2;
    for (int x = this->x - 1; x <= this->x + 1; x += 2)
    {
        int y = y_start - y_iterator; 
        for (int i = 0; i < x_quant; i++)
        {
            y += y_iterator;
            if (Board_Checkers.boundsCheck(x, y))
                continue;
            if (Board_Checkers.getColor(x, y) == nullptr)
            {
                //можно пушить мувмент в вектор
                //разбил на две части указатель
                Movement* move_temp = new Movement(this->x, this->y, x, y, nullptr, false);
                pointer_to_move move_p(move_temp);
                moves.push_back(move_p); 
            }
        }
    }
    all_moves_vector possibleJumps = this->make_attack_vector(Board_Checkers, nullptr);
    moves.insert(moves.end(), possibleJumps.begin(), possibleJumps.end());
    moves.shrink_to_fit();
    return moves;
}

all_moves_vector Cell::make_attack_vector(const Board_Checkers& Board_Checkers, const pointer_to_move previous) const
{
    all_moves_vector moves(0);
    int y_start;
    int y_iterator;
    int x_quant;
    if (isWhite)
    {
        y_start = this->y + 2;
        y_iterator = -4;
    }
    else 
    {
        y_start = this->y - 2;
        y_iterator = 4;
    }
    x_quant = 1;
    if (this->isDamka)
        x_quant = 2;      
    for (int x = this->x - 2; x <= this->x + 2; x += 4)
    {
        int y = y_start - y_iterator;
        for (int i = 0; i < x_quant; i++) 
        {
            y += y_iterator;
            if (Board_Checkers.boundsCheck(x, y))
                continue;
            if (previous != nullptr &&
                x == previous->get_Start()[0] && 
                y == previous->get_Start()[1])
                continue;
            Cell* attacked = Board_Checkers.getColor((this->x + x)/2 , (this->y + y)/2);
            if (attacked != nullptr &&
                attacked->isWhite != this->isWhite &&
                Board_Checkers.getColor(x, y) == nullptr)
            {
                pointer_to_move attack(new Movement(this->x, this->y, x, y, previous, true)); 
                moves.push_back(attack);
                Cell suppositive(x, y, this->isWhite);
                if (this->isDamka) {
                    suppositive.becomeDamka();
                }
                all_moves_vector nextMoves = suppositive.make_attack_vector(Board_Checkers, attack);
		        moves.insert(moves.end(), nextMoves.begin(), nextMoves.end());
            }
        }
    }





    moves.shrink_to_fit();
    return moves;
}

void Cell::Damka_Check(const Board_Checkers& Board_Checkers)
{
    if (isWhite && this->y == Board_Checkers::size - 1 || !isWhite && this->y == 0) {
        becomeDamka();
    }
}


std::string Cell::getLetter() const
{
    std::string letter;

    if (isWhite) {
        letter = "W";
    }
    else {
        letter = "B";
    }

    if (isDamka) {
        letter += "D";
    }
    else {
        letter += " ";
    }

    return letter;
}
