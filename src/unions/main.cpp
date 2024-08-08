#include "benchmarks.hpp"
#include "types.hpp"

#include <format>
#include <iostream>

int main(int argc, char *argv[])
{
    constexpr std::size_t n{500000};
    constexpr float dx{100};
    constexpr float dy{300};
    constexpr shape_color color{1, 2, 3, 127};
    constexpr unsigned int seed{475387};
    constexpr std::size_t r{11};

    double total_area;
    double elapsed;

    std::cout << "\"object-oriented\", \"tagged union\", \"variant\", \"data-oriented\"\n";

    for (size_t k = 0; k < r; ++k)
    {
        elapsed = benchmark_oop(n, seed, dx, dy, color, total_area);
        std::cout << std::format("{}, ", elapsed);

        elapsed = benchmark_tu(n, seed, dx, dy, color, total_area);
        std::cout << std::format("{}, ", elapsed);

        elapsed = benchmark_variant(n, seed, dx, dy, color, total_area);
        std::cout << std::format("{}, ", elapsed);

        elapsed = benchmark_dod(n, seed, dx, dy, color, total_area);
        std::cout << std::format("{}\n", elapsed);
    }
};
