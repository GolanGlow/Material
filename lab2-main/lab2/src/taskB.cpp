/// @file
/// @brief TaskB (see SNIPPETS.md for cli commands)

/// @todo add stdlib headers as needed

/// @todo toplevel description:
///     - namespace one: add two member functions to the given class 'Particle', see details below
///     - namespace two: implement the class `Particle` from scratch, see details below

namespace one
{

    struct Particle
    {
        double vx; ///< velocity in x-direction
        double vy; ///< velocity in y-direction
        double m;  ///< mass

        /// @todo implement the following **const** member functions:
        ///     - energy(): returns the kinetic energy of the particle (formula, see README.md)
        ///     - str(): returns a string representation of the member variables
    };

} // end namespace one

namespace two
{
    /// @todo implement a class `Particle` with the following properties:
    ///     - **private** member variables vx, vy, m
    ///     - constructor with three parameters (for the three member variables)
    ///     - set(): function to change the values of all three member variables
    ///     - get(): returns the values of the member variables in a tuple
    ///     - energy(): returns the kinetic energy of the particle (E_kin = 1/2 * m * (vx^2 + vy^2))
    ///     - str(): returns a string representation of the member variables


} // end namespace two

int main()
{

    /// @todo create instances of your `Particle`-classes from namespace `one` and `two` and call their member functions

    return 0;
}
