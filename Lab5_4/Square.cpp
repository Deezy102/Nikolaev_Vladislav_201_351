#include "Square.h"
Square::Square() {
	pos_x = 0;
	pos_y = 0;
	sq_side = 0;
}
Square::Square(int x, int y, int sd):Position(x,y)
{
	sq_side = sd;
	std::cout<< "\nSquare " << pos_x << " " << pos_y << " " << sq_side;
}
Square::~Square() {

}

void Square::set_sd(int sd)
{
	//std::cin >> sd;
	sq_side = sd;
}

int Square::get_sd()
{
	return sq_side;
}
