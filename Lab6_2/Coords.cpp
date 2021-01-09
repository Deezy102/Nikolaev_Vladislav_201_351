#include "Coords.h"
Coords::Coords(const Coords& A) {
	this->pos_x = A.pos_x;
	this->pos_y = A.pos_y;
	this->index = A.index;
	this->angle = A.angle;
}
Coords::Coords(int x, int y, int i) {
	pos_x = x;
	pos_y = y;
	index = i;
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
void Coords::set_index(int i) {
	index = i;
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
int Coords::get_index() {
	return index;
}

Coords& Coords::operator=(const Coords& A)
{
	pos_x = A.pos_x;
	pos_y = A.pos_y;
	index = A.index;
	angle = A.angle;
	return *this;
}
