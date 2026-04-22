/// @file
/// @brief TaskA (see SNIPPETS.md for cli commands)

/// @todo add stdlib headers as needed

/// @todo implement constructors for Point2D and Point3D, details see below

struct Point2D
{
    double x; ///< first dimension
    double y; ///< second dimension

    /// @todo implement three constructors using these parameters and use member initializer lists:
    /// 1. one value used to initialize all dimensions (x and y) is passed
    /// 2. one value for x, another one for y is passed
    /// 3. a std::array of length 2 is passed
};

struct Point3D
{
    double x; ///< first dimension
    double y; ///< second dimension
    double z; ///< third dimension

    /// @todo implement four constructors using these parameters:
    /// 1. one value used to initialize all dimensions (x, y, and z) is passed
    /// 2. three individual values are passed for x, y, z
    /// 3. a std::array of length 3 is passed
    /// 4. an instance of 'Point2D' for x, y and an additional value for z (default is 0.0) is passed
};

int main()
{
    /// @todo use each of your constructors and check (assertion) if they work as expected

    return 0;
}
