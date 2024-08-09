#pragma once
#pragma once
#include <cstdlib>

#include "types.hpp"
#include "tagged_union.hpp"
#include "variant.hpp"
#include "oop.hpp"
#include "dod.hpp"

#include <vector>
#include <chrono>
#include <memory>

constexpr float scale{1000};

inline shape_color random_color()
{
    shape_color color;
    for (auto &c : color)
    {
        c = std::rand() % 256;
    }
    return color;
}

inline point random_position(float scale = 1000.0f)
{
    return {std::rand() / scale, std::rand() / scale};
}

inline void initialise(std::size_t size,
                       unsigned int seed,
                       std::vector<tu::shape> &shapes)
{
    shapes.clear();
    shapes.reserve(size);
    std::srand(seed);
    for (std::size_t k = 0; k < size; k++)
    {
        point p = random_position();
        shape_color c = random_color();
        if (std::rand() < RAND_MAX / 2)
        {
            const float radius{std::rand() / scale};
            shapes.emplace_back(p, c, radius);
        }
        else
        {
            const float a{std::rand() / scale};
            const float b{std::rand() / scale};
            shapes.emplace_back(p, c, a, b);
        }
    }
}

inline void initialise(std::size_t size,
                       unsigned int seed,
                       std::vector<v::shape> &shapes)
{
    shapes.clear();
    shapes.reserve(size);
    std::srand(seed);
    for (std::size_t k = 0; k < size; k++)
    {
        point p = random_position();
        shape_color c = random_color();
        if (std::rand() < RAND_MAX / 2)
        {
            const float radius{std::rand() / scale};
            shapes.push_back(v::circle{p, c, radius});
        }
        else
        {
            const float a{std::rand() / scale};
            const float b{std::rand() / scale};
            shapes.push_back(v::rectangle{p, c, a, b});
        }
    }
}

inline void initialise(std::size_t size,
                       unsigned int seed,
                       std::vector<std::unique_ptr<oop::basic_shape>> &shapes)
{

    shapes.clear();
    shapes.reserve(size);
    std::srand(seed);
    for (std::size_t k = 0; k < size; k++)
    {
        point p = random_position();
        shape_color c = random_color();
        if (std::rand() < RAND_MAX / 2)
        {
            const float radius{std::rand() / scale};
            shapes.emplace_back(new oop::circle(p, c, radius));
        }
        else
        {
            const float a{std::rand() / scale};
            const float b{std::rand() / scale};
            shapes.emplace_back(new oop::rectangle(p, c, a, b));
        }
    }
}

inline void initialise(std::size_t size,
                       unsigned int seed,
                       dod::shapes &shapes)
{
    shapes = dod::shapes{};
    shapes.reserve(size);
    std::srand(seed);
    for (std::size_t k = 0; k < size; k++)
    {
        shapes.origins.push_back(random_position());
        shapes.colors.push_back(random_color());

        if (std::rand() < RAND_MAX / 2)
        {
            shapes.circles.push_back(std::rand() / scale);
        }
        else
        {
            const float a{std::rand() / scale};
            const float b{std::rand() / scale};
            shapes.rectangles.push_back({a, b});
        }
    }
}
