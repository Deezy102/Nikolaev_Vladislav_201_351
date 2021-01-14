#include "Coords.h"
Coords::Coords(const Coords& A) {
	this->pos_x = A.pos_x;
	this->pos_y = A.pos_y;
	this->angle = A.angle;
}
Coords::Coords(int x, int y) {
	pos_x = x;
	pos_y = y;
	angle = 0;
}
Coords::~Coords() {
}
void Coords::set_angle(double n_angle) {
	angle = n_angle;
}
void Coords::set_x(int x) {
	pos_x = x;
}
void Coords::set_y(int y) {
	pos_y = y;
}

double Coords::get_angle() {
	return angle;
}
int Coords::get_y() {
	return pos_y;
}
int Coords::get_x() {
	return pos_x;
}

Coords& Coords::operator=(const Coords& A)
{
	pos_x = A.pos_x;
	pos_y = A.pos_y;
	angle = A.angle;
	return *this;
}

bool operator==(const Coords& left, const Coords& right)
{
	return ((left.pos_x == right.pos_x)
		&& (left.pos_y == right.pos_y));
}
