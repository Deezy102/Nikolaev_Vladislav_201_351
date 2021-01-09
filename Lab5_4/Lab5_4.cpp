//#include "Position.h"
#include "CircInSq.h"
#include <iostream>

int main()
{
    CircInSq P(100, 200, 20, 30);
    CircInSq D;

    std::cout << "Matrix 1:";
    std::cout << "\nX: " << P.get_x() << "\nY: " << P.get_y()
        << "\nSide: " << P.get_sd() << "\nRadius: " << P.get_r();
    
    D.set_x(3);
    D.set_y(2);
    D.set_r(4);
    D.set_sd(5);
    std::cout << "\n\nMatrix 2:\n";
    std::cout << "X: " << D.get_x() << "\nY: " << D.get_y()
        << "\nSide: " << D.get_sd() << "\nRadius: " << D.get_r();
   
}

