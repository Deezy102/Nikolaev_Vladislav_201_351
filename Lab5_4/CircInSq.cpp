#include "CircInSq.h"

CircInSq::CircInSq()
{
	pos_x = 0;
	pos_y = 0;
	circ_r = 0;
	sq_side = 0;
}

CircInSq::CircInSq(int x, int y, int R, int sd)
{
	pos_x = x;
	pos_y = y;
	circ_r = R;
	sq_side = sd;
}

CircInSq::~CircInSq()
{
}
