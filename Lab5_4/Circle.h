#pragma once
#include "Position.h"

class Circle :
    public virtual Position
{
protected:
    int circ_r;
public:
    Circle();
    Circle(int x, int y, int R);
    ~Circle();
    void set_r(int r);
    int get_r();
};

