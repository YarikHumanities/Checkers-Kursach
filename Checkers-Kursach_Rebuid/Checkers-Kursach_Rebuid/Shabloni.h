
#include <vector>
#include <array>
#include <memory>
#include <unordered_map>
#include <vector>
#include <cstdlib>

class Movement;


typedef std::array<int, 2> coordinates;


typedef std::vector<std::shared_ptr<Movement>> all_moves_vector;
typedef std::shared_ptr<Movement> pointer_to_move;


