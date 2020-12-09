#include "Circle.h"

Circle::Circle()
{
	pos_x = 0;
	pos_y = 0;
	circ_r = 0;
}

Circle::Circle(int x, int y, int R):Position(x,y)
{
	circ_r = R;
	std::cout <<"\ncirc " <<pos_x << " " << pos_y << " " << circ_r;
}

Circle::~Circle()
{
}

void Circle::set_r(int r)
{
	//std::cin >> r;
	circ_r = r;
}
int Circle::get_r() {
	return circ_r;
}