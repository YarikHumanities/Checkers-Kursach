
#include <unordered_map>
using namespace std;
class Board_Checkers;

class AIPlayer
{
public:
	AIPlayer(bool isWhite) : isWhite(isWhite) {};
	void getMovement(Board_Checkers& Board_Checkers);



private:
	bool isWhite;
	
};


