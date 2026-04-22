/// @file
/// @brief Task3: implementation

#include <filesystem> // std::filesystem::path
#include <iostream>   // std::vector
#include <vector>     // std::cout

#include "task2.hpp" // task2::BBox, task2::Circle, task2::Triangle

#include "task2.misc.hpp" // task2::operator<<, task2::isclose

#include "task3.hpp"      // task3::render_something
#include "task3.misc.hpp" // task3::render_wrapper

#include "iue-rnd/random.hpp" // iue::rnd::UniformValue, iue::rnd::UniformCircle, iue::rnd::UniformTriangle

/// @todo Include additional standard library headers as needed

namespace task3
{

    /// @todo Implement function 'render_something' as declared and specified in task3.hpp
    /// Implementation Hints:
    /// 1. You can plot whatever you want, but you need to plot at least 200 primitives!
    /// 2. You can view .svg-files using your web browser (or installing a VSCode extension to preview SVGs)
    /// 3. Use the provided function 'task3::render_wrapper' from 'task3.misc.hpp' to plot task2::BBox, task2::Circle,
    ///    task2::Triangle to a SVG-file
    /// 4. The idea is that you make use of the functionality (scale/translate/rotate) you implemented in task2
    /// 5. Optional: you can make use of the random Generators in 'iue-rnd/random.hpp' to obtain random values,
    ///    circles, and triangles
    int render_something(std::filesystem::path filepath)
    {
        /// @note below is only a demo/boilerplate, adapt as needed
        std::vector<task2::BBox> bboxes;
        {
            auto gen = iue::rnd::UniformValue(0.0, 5);
            for (int i = 0; i < 20; ++i)
            {
                task2::Vec2d min = {gen(), gen() + 5.0};
                task2::Vec2d max = {min[0] + 0.1, min[1] + 0.1};
                task2::BBox box = {min, max};
                bboxes.push_back(box);
            }
            for (int i = 0; i < 20; ++i)
            {
                task2::Vec2d min = {gen() + 5.0, gen()};
                task2::Vec2d max = {min[0] + 0.2, min[1] + 0.2};
                task2::BBox box = {min, max};
                bboxes.push_back(box);
            }            
        }

        std::vector<task2::Circle> circles;
        {
            auto gen = iue::rnd::UniformValue(0.0, 5);
            for (int i = 0; i < 20; ++i)
            {
                task2::Vec2d center = {gen(), gen()};
                double radius = 0.1;
                task2::Circle circle = {center, radius};
                circles.push_back(circle);
            }
        }

        std::vector<task2::Triangle> triangles;
        {
            auto gen = iue::rnd::UniformValue(5.0, 10.0);
            for (int i = 0; i < 20; ++i)
            {
                auto a = task2::Vec2d{gen(), gen()};
                auto b = task2::Vec2d{a[0] + 0.1, a[1]};
                auto c = task2::Vec2d{b[0], b[1] + 0.1};
                task2::Triangle triangle = {{a, b, c}};
                triangles.push_back(triangle);
            }
        }

        auto [bbmin, bbmax] = task3::render_wrapper(filepath, bboxes, circles, triangles);
        std::cout << task2::BBox{bbmin, bbmax} << "\n";
        return triangles.size() + bboxes.size() + circles.size();
    };

} // namespace task3
