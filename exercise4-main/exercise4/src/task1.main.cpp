/// @file
/// @brief Task1: "single-file" excutable C++ program

#include <array> // std::array

/// @todo Include standard library headers as needed

namespace task1
{

    using Coord = std::array<double, 2>;

    /// @todo Implement a function 'rotate_counter_clockwise':
    /// - the function receives a two-dimensional coordinate in form of a 'std::array<double, 2>'
    /// - the function receives a rotation angle (in radians) in form of a 'double'
    /// - the function rotates the coordinate counter clockwise around the origin
    /// - the function returns the rotated coordinate as a std::array<double, 2>

} // namespace task1

int main()
{
    using namespace task1;

    /// @todo
    /// 1. Create two coordinates (local variables) {112,211} and {-42,23}
    /// 2. Use your 'rotate_counter_clockwise' function to rotate both coordinates by 180 degrees
    /// 3. Capture the results of your function calls in a local variable.
    /// 4. Print the results to the console.
    /// Hint: the expected coordinates after rotating 180 degrees are
    ///   {112,211} -> {-112,-211}
    ///   {-42,23}  -> {42,-23}

    return 0;
}
