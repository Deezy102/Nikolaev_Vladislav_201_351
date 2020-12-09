#pragma once
#include "Position.h"
class Square : public virtual Position
{
protected:	
	int sq_side;
public:
	Square();
	Square(int x, int y, int sd);
	~Square();
	void set_sd(int sd);
	int get_sd();
};

