#pragma once
#include "Circle.h"
#include "Square.h"
class CircInSq: public Square, public Circle
{
private:

public:
	CircInSq();
	CircInSq(int x, int y, int R , int sd );
	~CircInSq();

};

