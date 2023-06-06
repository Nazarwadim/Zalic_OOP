#include <iostream>
#include "Matrix.h"
int main()
{
    try {
        Matrix mx1(2, 1);
        mx1.at(1, 0) = 3;
        Matrix mx2(2, 2);

        mx2.at(0, 0) = 1;
        std::cout <<  (mx1==mx2);
    }
    catch(std::exception *ex)
    {
        std::cout << ex->what();
    }
}