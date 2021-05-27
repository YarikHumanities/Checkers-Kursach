#include "HumanPlayer.h"

#include "Board_Checkers.h"
#include "Movement.h"
#include "Cell.h"
#include "Shabloni.h"

#include <array>
#include <exception>
#include <iostream>

using namespace std;
//void triggerEndGame();
Cell* HumanPlayer::get_coodr_from(const Board_Checkers& Board_Checkers)
{
    
    while (true)
    { 
        string coord_u;
        cout << getColor() << ", select cell and enter the coordinates:" << '\n';


        try
        {
            getline(cin, coord_u);
            /*if (coord_u == "exit")
            {
                triggerEndGame();
                return nullptr;
            }*/
            if (coord_u.length() < 2) {
                throw ("You have mistaken, enter coordinates like this <letter><number>'.");
            }

           if (coord_u[0] >= 'A' && coord_u[0] <= 'Z') {
               coord_u[0] = coord_u[0] + 32;
            }

            char letter = coord_u[0];
            char number = coord_u[1];

            if (isdigit(letter)) 
            {
                letter = number;
                number = coord_u[0];
            }   
          
            int x = letter - 97;
            int y = number - 49;
            if (Board_Checkers.boundsCheck(x, y))
                throw ("Please enter a coordinate on the Board (now press 'Enter')");              
            
            
            Cell* currentCell = Board_Checkers.getColor(x, y);
            if (currentCell == nullptr) {
                cout << "There is nothing on this cell"<<endl << endl;
            }
            else if (currentCell->isWhite != this->isWhite) {
                cout << "That's not your cell" << endl<<endl;
            }

            else {
                return Board_Checkers.getColor(x, y);
            }
        }
        catch (const char* e)
        {
           cout << e << '\n';
           cin.ignore(32767, '\n');
           cin.clear();
        }
    }
}
    

pointer_to_move HumanPlayer::get_move_from(const all_moves_vector possibleMovements)
{
    int number;
    while (true)
    {   
        std::cout << getColor() << ", please select a movement by its number on the board (or enter 0 to go back): ";
        try 
        {
            std::cin >> number;
            if (!std::cin.good()) {
                throw ("Please enter a number.");
            }
            else if (number > possibleMovements.size()) {
                throw ("Please enter one of the numbers on the board, your number was too big (or enter 0 to go back)");
            }


            else if (number == 0) {
                return nullptr;
            }

            cin.ignore(32767, '\n'); {
                return possibleMovements[number - 1];
            }
        }
        catch (const char* e)
        {
            std::cout << e << '\n';
            std::cin.ignore(32767, '\n');
            std::cin.clear();
        }
    }
}

void HumanPlayer::getMovement(Board_Checkers& Board_Checkers)
{
    print_board(Board_Checkers);
    all_moves_vector possibleMovements;
    while (true)
    {
        Cell* pieceMoving = get_coodr_from(Board_Checkers);
        if (pieceMoving == nullptr)
            return;
        possibleMovements = pieceMoving->make_move_vector(Board_Checkers);
        if (possibleMovements.empty())
            std::cout << "That piece has no possible Movements! Please choose another:" << '\n';
        else
        {
            print_board(Board_Checkers, possibleMovements);
            pointer_to_move Movement = get_move_from(possibleMovements);
            if (Movement != nullptr)
            {
                Board_Checkers.make_steps(Movement, pieceMoving);
                return;
            }
        }
    }
}





void HumanPlayer::print_board(const Board_Checkers& Board_Checkers, const all_moves_vector possibleMovements)
{
    system("CLS");
    for (int y = -1; y < Board_Checkers::size; y++)
    {
        for (int x = -1; x < Board_Checkers::size; x++)
        {
            if (y == -1)
            {
                if (x != -1)
                    std::cout << "-" << (char)(x + 65) << "- ";
                else
                    std::cout << "     ";
            }
            
            else if (x == -1)
            {
                if (y != -1)
                    std::cout << "-" << y + 1 << "- ";
            }
            else
            {
                Cell* thisPiece = Board_Checkers.getColor(x, y);
                if (!possibleMovements.empty())
                {
                    bool MovementFound = false;
                    for (unsigned int i = 0; i < possibleMovements.size(); i++)
                    {
                        coordinates Movement = possibleMovements[i]->get_Finish();
                        if (Movement[0] == x && Movement[1] == y)
                        {
                            std::cout << "| " << i + 1 << " ";
                            MovementFound = true;
                        }
                    }
                    if (MovementFound)
                        continue;
                }
                if (thisPiece != nullptr)
                    std::cout << "| " << thisPiece->getLetter();
                else if (Board_Checkers.right_place(x, y))
                    std::cout << "| . ";
                else
                    std::cout << "|   ";
            }
        }
        std::cout << '\n';
    }
}


void HumanPlayer::print_board(const Board_Checkers& Board_Checkers)
{
    static all_moves_vector emptyPossibleMovements(0);
    print_board(Board_Checkers, emptyPossibleMovements);
}



std::string HumanPlayer::getColor()
{
    return isWhite ? "White" : "Black";
}
