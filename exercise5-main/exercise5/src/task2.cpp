/// @file
/// @brief Task2: member function definitions/implementations

#include "task2.hpp" // task2::select, task2::select_union

#include <array>         // std::array
#include <functional>    // std::function
#include <unordered_set> // std::unordered_set
#include <vector>        // std::vector

namespace task2
{

    /// @todo Implement function 'select' as declared and specified in task2.hpp
    std::unordered_set<size_t> select(const std::vector<Vec2d>& vertices, const Region& region, bool invert)
    {
        std::unordered_set<size_t> selected = {};
        return selected;
    }

    /// @todo Implement function 'select_union' as declared and specified in task2.hpp
    std::unordered_set<size_t>
    select_union(const std::vector<Vec2d>& vertices, const std::vector<Region>& regions, bool invert)
    {
        std::unordered_set<size_t> selected = {};
        return selected;
    }

} // namespace task2
