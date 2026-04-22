// File main.cpp
#include "point.hpp"

int main() {
    Point myPoint = {1, 2};
    myPoint.printCoordinates();
    std::cout << std::endl;

    myPoint.setCoordinates(3, 2);
    std::cout << "sum of x and y when ";
    myPoint.printCoordinates();
    std::cout << " is " << myPoint.sum() << std::endl;
    return 0;
}
