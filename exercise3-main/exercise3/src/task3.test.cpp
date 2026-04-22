/// @file
/// @brief Task3: Tests
/// compile & run command:
///   mkdir -p build output && g++ -std=c++20 -Iinclude src/task2.cpp src/task3*.cpp -o build/task3 && ./build/task3

#include "task3.hpp"
#include "task2.hpp"

#include "iue-io/csv.hpp"

#include <cassert>    // assert
#include <cmath>      // std::sin
#include <filesystem> // std::filesystem::remove
#include <iostream>   // std::cout|endl
#include <numbers>    // std::numbers::pi

int main()
{

    {
        auto start = 0.0;
        auto end = 2 * std::numbers::pi;

        auto func = [](double x) { return std::cos(x); };
        auto derivative = [](double x) { return -std::sin(x); };
        auto Func = [](double x) { return std::sin(x); };
        auto integral = [&Func, &start](double x) { return Func(x) - Func(start); };

        auto n = 36U;
        std::filesystem::path filename = "output/test.task3.cos.csv";
        std::filesystem::remove(filename);

        // genrate table
        sample_derivate_and_antiderivative_to_csv(func, {start, end}, n, filename, ';');

        { // check table
            auto table = iue::io::loadcsv(filename, ';');
            assert(table.size() == n);
            auto [xi, dx] = range(start, end, n);
            for (auto i = 0U; i != table.size(); ++i)
            {
                auto row = table[i];
                assert(row.size() == 4);
                auto [x, f, F, df] = std::tie(row[0], row[1], row[2], row[3]);

                assert(std::abs(x - xi[i]) < 1e-7);
                assert(std::abs(f - func(xi[i])) < 1e-7);
                assert(std::abs(df - derivative(xi[i])) < 1e-1);
                assert(std::abs(F - integral(xi[i])) < 1e-2);
            }
        }
    }

    {
        auto start = 0.0;
        auto end = 2 * std::numbers::pi;

        auto func = [](double x) { return std::sin(x); };
        auto derivative = [](double x) { return std::cos(x); };
        auto Func = [](double x) { return -std::cos(x); };
        auto integral = [&Func, &start](double x) { return Func(x) - Func(start); };

        auto n = 360U;

        std::filesystem::path filename = "output/test.task3.sin.csv";
        std::filesystem::remove(filename);

        // genrate table
        sample_derivate_and_antiderivative_to_csv(func, {start, end}, n, filename, ';');

        { // check table
            auto table = iue::io::loadcsv(filename, ';');
            assert(table.size() == n);
            auto [xi, dx] = range(start, end, n);
            for (auto i = 0U; i != table.size(); ++i)
            {
                auto row = table[i];
                assert(row.size() == 4);
                auto [x, f, F, df] = std::tie(row[0], row[1], row[2], row[3]);

                assert(std::abs(x - xi[i]) < 1e-7);
                assert(std::abs(f - func(xi[i])) < 1e-7);
                assert(std::abs(df - derivative(xi[i])) < 1e-2);
                assert(std::abs(F - integral(xi[i])) < 1e-3);
            }
        }
    }

    std::cout << "task3.test.cpp: all asserts passed" << std::endl;

    return 0;
}
