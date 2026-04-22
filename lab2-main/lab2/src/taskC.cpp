/// @file
/// @brief TaskC (see SNIPPETS.md for cli commands)

#include <tuple>

/// @todo add stdlib headers as needed

/// @todo implement the class 'PolyOrder2' with the following properties:
///     - member variable(s) to store the three coefficients of a second-order polynomial
///     - constructor that lets the user initialize the three coefficients
///     - print(): prints the polynomial including the actual coefficients to the console
///     - overloaded `operator()` operator to evaluate the polynomial at a user prodived coordinate

int main()
{

    auto [a0, a1, a2] = std::tuple{1.0, 2.0, 3.0}; ///< given coefficients
    auto x = 1.0;                                  ///< given coordinate 'x' for evaluation

    /// @todo
    /// 1. create an instance of your class and pass the coefficients given above on construction
    /// 2. define a lambda function to also evaluate the polynomial with the given coefficients
    ///     - the coefficients should be captured from the enclosing scope
    ///     - the point of evaluation 'x' is passed as argument
    /// 3. evaluate the polynomial at the given coordinate and print the result twice:
    ///     - once using your class
    ///     - once using your lambda function

    return 0;
}
