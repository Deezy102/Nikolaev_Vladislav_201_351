#pragma once
#include <iostream>
class Position
{
protected:
	int pos_x;
	int pos_y;
public:
	Position();
	Position(int x, int y);
	~Position();
	void set_x(int x);
	void set_y(int y);
	int get_x();
	int get_y();
};

