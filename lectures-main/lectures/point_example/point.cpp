// File point.cpp
#include "point.hpp"

// Member function to set the coordinates of the Point
void Point::setCoordinates(int x_val, int y_val) {
    x = x_val;
    y = y_val;
}

// Member function to return the sum of the coordinates
int Point::sum() {
    return x + y;
}

// Member function to print the coordinates of the Point
void Point::printCoordinates() {
    std::cout << "x = " << x << ", y = " << y;
}
