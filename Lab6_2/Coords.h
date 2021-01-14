#pragma once
class Coords
{
protected:
	int pos_x;
	int pos_y;
	double angle;
public:
	Coords(const Coords& A);
	Coords(int x, int y);
	~Coords();
	void set_x(int x);
	void set_y(int y);

	void set_angle(double n_angle);
	double get_angle();
	int get_x();
	int get_y();
	Coords& operator=(const Coords& A);
	friend bool operator==(const Coords& left, const Coords& right);
};
