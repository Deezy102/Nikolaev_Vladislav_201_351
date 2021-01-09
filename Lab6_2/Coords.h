#pragma once
class Coords
{
protected:
	int pos_x;
	int pos_y;
	int index;
	double angle;
public:
	Coords(const Coords& A);
	Coords(int x, int y, int i);
	~Coords();
	void set_x(int x);
	void set_y(int y);
	void set_index(int i);
	void set_angle(double n_angle);
	double get_angle();
	int get_x();
	int get_y();
	int get_index();
	Coords& operator=(const Coords& A);
};

