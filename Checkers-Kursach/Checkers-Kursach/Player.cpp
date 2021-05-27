#include "Player.h"
//#include "Shabloni.h"
#include <string>
#include <iostream>

Cell* Player::get_coodr_from(const Board_Checkers& board_checkers) {
	while (true) {
		std::string cell_name;
		std::cout << "Enter your cell: " << std::endl;
		getline(std::cin, cell_name);
		char letter = cell_name[0];
		char number = cell_name[1];
		int x = letter - 97;
		int y = number - 49;
		Cell* our_cell = board_checkers.getColor(x, y);
		if (our_cell == nullptr) {
			std::cout << "No figure here" << std::endl;
		}
		else if (our_cell->isWhite != this->isWhite) {
			std::cout << "That is not yours" << std::endl;
		}
		else
			return board_checkers.getColor(x, y);
			//return our_cell;
		

	}
}
pointer_to_move Player::get_move_from(const all_moves_vector all_moves) {
	int cell_number;
	while (true) {
		std::cout << "Enter your move cell: ";
		std::cin >> cell_number;
		
		std::cin.ignore(32767, '\n');
		return all_moves[cell_number - 1];
	}
}
void Player::print_board(const Board_Checkers& board_checkers, const all_moves_vector all_moves) {
	system("cls");
	for (int y = -1; y < Board_Checkers::size; y++)
	{
		for (int x = -1; x < Board_Checkers::size; x++)
		{
			if (y == -1) {
				if (x != -1) {
					std::cout << "-" << (char)(x + 65) << "-";
				}
				else {
					std::cout << "     ";
				}
			}
			else if (x == -1) {
				if (y != -1) {
					std::cout << "-" << y + 1 << "- ";
				}
			}
			else {
				Cell* current_cell = board_checkers.getColor(x, y);
				//if (!all_moves.empty()) {
				//дописать это!!!
				//}
				if (current_cell != nullptr) {
					std::cout << "| " << current_cell->getLetter();
				}
				else
					std::cout << "|   ";
			}
		}
		std::cout << std::endl;
	}
}

void Player::print_board(const Board_Checkers& board_checkers) {
	all_moves_vector moves(0);
	print_board(board_checkers, moves);
}

void Player::form_move(Board_Checkers& board_checkers){
	print_board(board_checkers);
	all_moves_vector possible_moves;
	while (true) {
		Cell* moved_cell = get_coodr_from(board_checkers);
		if (moved_cell == nullptr) {
			continue;
		}
		possible_moves = moved_cell->make_move_vector(board_checkers);
		if (possible_moves.empty()) {
			std::cout << "No moves here, try again" << std::endl;
		}
		else {
			print_board(board_checkers, possible_moves);
			pointer_to_move chosen_move = get_move_from(possible_moves);

			if (chosen_move!=nullptr) {
				board_checkers.make_steps(chosen_move, moved_cell);
			}
		}
	}
}
