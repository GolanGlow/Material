/// @file
/// @brief Task3: function declarations

#pragma once

#include <filesystem> // std::filesystem::path
#include <functional> // std::function
#include <tuple>      // std::tuple

/// @brief Samples a one-dimensional scalar function (f) including its derivative (df) and antiderivative (F):
///  - The derivative (df) and antiderivative (F) are approximated numerically
///  - The sampled values are recorded in a CSV-file in this form:
///   - csv-column layout: x, f(x), F(x), df(x)
/// @param func Function to be sampled as callable with a signature compatible with f(double) -> double
/// @param interval Sampling interval
/// @param n Number of equidistant sampling points to use (assumption: n >= 2)
/// @param filepath Filename for the output CSV-file
/// @param del Delimiter using for the CSV output

void sample_derivate_and_antiderivative_to_csv(std::function<double(double)> func,
                                               std::tuple<double, double> interval,
                                               unsigned int n,
                                               std::filesystem::path filepath,
                                               char del);
