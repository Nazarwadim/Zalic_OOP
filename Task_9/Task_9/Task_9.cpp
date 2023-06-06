#include <iostream>
#include "Matrix.h"
int main()
{
    Matrix mx1(2, 2);
    mx1.at(1, 0) = 3;
    Matrix mx2(2, 2);

    mx2.at(0,0) = 1;
    std::cout << mx1;
}