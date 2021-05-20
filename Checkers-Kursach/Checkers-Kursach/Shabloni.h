#pragma once
#include <array>
#include <vector>
#include <memory>

class Move;
typedef std::array<int, 2> coordinates;
typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;