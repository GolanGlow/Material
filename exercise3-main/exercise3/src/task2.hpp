/// @file
/// @brief Task2: function declarations

#pragma once

#include <functional> // std::function
#include <tuple>      // std::tuple
#include <vector>     // std::vector

/// @brief Creates a sequence of equidistant values in a given interval (inclusive).
/// @param start Start of the interval
/// @param end End of the interval
/// @param n Number of values (assertion: n >= 2)
/// @return A tuple of {Sequence of equidistant values in increasing order, spacing}
std::tuple<std::vector<double>, double> range(double start, double end, unsigned int n);

/// @brief Evaluates a one-dimensional scalar function at the provided discrete locations
/// @param values Sequence of discrete locations
/// @param func Callable with a signature compatible with f(double) -> double
/// @return Sequence of function values
std::vector<double> sample(std::vector<double> values, std::function<double(double)> func);

/// @brief Performs a numerical differentiation using a combined forward/center/backward difference scheme:
/// - forward difference for the first value in the interval
/// - backward difference for the last value in the interval
/// - central difference for all other values contained in the interval
/// @param y Discrete sequence of function values (assertion: two or more values)
/// @param dx Equidistance between evaluation points of function values
/// @return Sequence of function values of the numerical derivative
std::vector<double> numdiff(std::vector<double> y, double dx);

/// @brief Performs a numerical integration of an interval using the trapezoidal rule
/// @param y Discrete sequence of function values representing the interval to integrate
///        (assertion: two or more values)
/// @param dx Equidistance between evaluation points of function values
/// @return Sequence of values for the numerical integral
std::vector<double> numint(std::vector<double> y, double dx);
