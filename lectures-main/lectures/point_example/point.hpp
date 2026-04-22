// File point.hpp
#pragma once        // Prevent multiple inclusions
#include <iostream> // std::cout

// Define a struct called Point
struct Point {
    int x;
    int y;

    // Member function to set the coordinates of the point
    void setCoordinates(int x_val, int y_val);

    // Member function to return the sum of the coordinates
    int sum();

    // Member function to print the coordinates of the Point
    void printCoordinates();
};
