#pragma once
#include "initialise.hpp"

#include <iostream>
#include <vector>
#include <chrono>
#include <memory>
#include <type_traits>

inline double benchmark_tu(std::size_t size,
                           unsigned int seed,
                           float translate_x,
                           float translate_y,
                           const shape_color &new_color,
                           double &total_area)
{
    std::vector<tu::shape> shapes;
    initialise(size, seed, shapes);
    total_area = 0;
    const auto t0 = std::chrono::high_resolution_clock::now();
    for (auto &s : shapes)
    {
        s.origin.x += translate_x;
        s.origin.y += translate_y;
        s.color = new_color;
        total_area += tu::area(s);
    }
    const auto dt = std::chrono::high_resolution_clock::now() - t0;
    return std::chrono::duration_cast<std::chrono::microseconds>(dt).count();
}

inline double benchmark_variant(std::size_t size,
                                unsigned int seed,
                                float translate_x,
                                float translate_y,
                                const shape_color &new_color,
                                double &total_area)
{
    std::vector<v::shape> shapes;
    initialise(size, seed, shapes);
    total_area = 0;
    const auto t0 = std::chrono::high_resolution_clock::now();
    for (auto &s : shapes)
    {
        total_area += std::visit([&translate_x, &translate_y, &new_color](auto &arg) -> double
                                 {  arg.origin.x += translate_x ;
                                    arg.origin.y += translate_y;
                                    arg.color = new_color;
                                    using T = std::decay_t<decltype(arg)>; 
                                    if constexpr(std::is_same_v<T, v::circle>)
                                    {
                                        return 3.1415926535f * arg.radius * arg.radius;
                                    }
                                    else if constexpr(std::is_same_v<T, v::rectangle>)
                                    {
                                        return arg.a * arg.b;
                                    }
                                    else 
                                    { 
                                        return -1;
                                    } },
                                 s);
    }
    const auto dt = std::chrono::high_resolution_clock::now() - t0;
    return std::chrono::duration_cast<std::chrono::microseconds>(dt).count();
}

inline double benchmark_oop(std::size_t size,
                            unsigned int seed,
                            float translate_x,
                            float translate_y,
                            const shape_color &new_color,
                            double &total_area)
{
    std::vector<std::unique_ptr<oop::basic_shape>> shapes;
    initialise(size, seed, shapes);
    total_area = 0;
    const auto t0 = std::chrono::high_resolution_clock::now();
    for (auto &s : shapes)
    {
        s->origin.x += translate_x;
        s->origin.y += translate_y;
        s->color = new_color;
        total_area += s->area();
    }
    const auto dt = std::chrono::high_resolution_clock::now() - t0;
    return std::chrono::duration_cast<std::chrono::microseconds>(dt).count();
}

inline double benchmark_dod(std::size_t size,
                            unsigned int seed,
                            float translate_x,
                            float translate_y,
                            const shape_color &new_color,
                            double &total_area)
{
    dod::shapes shapes;
    initialise(size, seed, shapes);
    total_area = 0;
    const auto t0 = std::chrono::high_resolution_clock::now();
    for (auto &p : shapes.origins)
    {
        p.x += translate_x;
        p.y += translate_y;
    }

    for (auto &c : shapes.colors)
    {
        c = new_color;
    }

    for (const auto &r : shapes.circles)
    {
        total_area += 3.1415926535f * r * r;
    }

    for (const auto &s : shapes.rectangles)
    {
        total_area += s.width * s.height;
    }
    const auto dt = std::chrono::high_resolution_clock::now() - t0;
    return std::chrono::duration_cast<std::chrono::microseconds>(dt).count();
}
