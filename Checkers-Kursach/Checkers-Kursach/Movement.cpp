#include "Movement.h"
#include "Board_Checkers.h"
#include "Cell.h"
#include "Shabloni.h"
#include <vector>
coordinates Movement::get_Start() const {
	coordinates start_placing;
	start_placing[0] = this->x1;
	start_placing[1] = this->y1;
	return start_placing;
}
coordinates Movement::get_Finish() const {
	coordinates end_placing;
	end_placing[0] = this->x2;
	end_placing[1] = this->y2;
	return end_placing;
}

