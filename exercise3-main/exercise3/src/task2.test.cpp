/// @file
/// @brief Task2: Tests
/// compile & run command:
///   mkdir -p build && g++ -std=c++20 src/task2*.cpp -o build/task2 && ./build/task2

#include "task2.hpp"

#include <cassert>  // assert
#include <cmath>    // std::abs|sin
#include <iostream> // std::cout|endl
#include <vector>   // std::vector

int main()
{

    { // testing function 'range'
        auto [x, dx] = range(0, 10, 11);
        assert(std::abs(dx - 1.0) < 1e-7);
        for (unsigned int i = 1; i != x.size(); ++i)
            assert(std::abs(x[i] - x[i - 1] - dx) < 1e-7);
    }

    { // testing functions 'range' and 'sample'
        auto [x, dx] = range(2, 10, 6);
        std::vector<double> f = sample(x, [](double x) { return std::sin(x); });
        for (unsigned int i = 0; i != x.size(); ++i)
            assert(std::abs(f[i] - std::sin(x[i])) < 1e-7);
    }

    { // testing functions 'range' and 'sample'
        auto [x, dx] = range(0, 5, 6);
        std::vector<double> f = sample(x, [](double x) { return std::cos(x); });
        for (unsigned int i = 0; i != x.size(); ++i)
            assert(std::abs(f[i] - std::cos(x[i])) < 1e-7);
    }

    { // testing function 'numdiff'

        double start = 1;
        double end = 4;

        double m = 10;
        auto f = [&m](double x) { return m * x; };
        auto df = [&m](double) { return m; };
        auto expected = [&df](double x) { return df(x); };

        int n = 5;
        auto [xi, dx] = range(start, end, n);
        auto fi = sample(xi, f);
        auto dfi = numdiff(fi, dx);

        for (int i = 0; i != n; ++i)
            assert(std::abs(dfi[i] - expected(xi[i])) < 1e-7);
    }

    { // testing function 'numdiff'

        double start = -2;
        double end = 4;

        auto f = [](double x) { return std::sin(x); };
        auto df = [](double x) { return std::cos(x); };
        auto expected = [&df](double x) { return df(x); };

        int n = 10'000;
        auto [xi, dx] = range(start, end, n);
        auto fi = sample(xi, f);
        auto dfi = numdiff(fi, dx);

        for (int i = 0; i != n; ++i)
            assert(std::abs(dfi[i] - expected(xi[i])) < 1e-3);
    }

    { // testing function 'numint'

        double start = 1;
        double end = 4;
        double m = 10;
        auto f = [&m](double x) { return m * x; };
        auto F = [&m](double x) { return (0.5 * m * x * x); };
        auto expected = [&F, &start](double x) { return F(x) - F(start); };

        int n = 10;
        auto [xi, dx] = range(start, end, n);
        auto fi = sample(xi, f);
        auto Fi = numint(fi, dx);
        for (int i = 0; i != n; ++i)
            assert(std::abs(Fi[i] - expected(xi[i])) < 1e-7);
    }

    { // testing function 'numint'

        double start = 1;
        double end = 4;

        auto f = [](double x) { return std::sin(x); };
        auto F = [](double x) { return -std::cos(x); };
        auto expected = [&F, &start](double x) { return F(x) - F(start); };

        int n = 10'000;
        auto [xi, dx] = range(start, end, n);
        auto fi = sample(xi, f);
        auto Fi = numint(fi, dx);
        for (int i = 0; i != n; ++i)
            assert(std::abs(Fi[i] - expected(xi[i])) < 1e-7);
    }

    std::cout << "task2.test.cpp: all asserts passed" << std::endl;

    return 0;
}
