#include "Position.h"

Position::Position() {
	pos_x = 0;
	pos_y = 0;
}
Position::Position(int x, int y) {
	pos_x = x;
	pos_y = y;
	std::cout << x << " " << y;
}
Position::~Position() {

}
void Position::set_x(int x) {
	//std::cin >> x;
	pos_x = x;
	
}
void Position::set_y(int y) {
	//std::cin >> y;
	pos_y = y;
	
}
int Position::get_y() {
	return pos_y;
}
int Position::get_x() {
	return pos_x;
}
