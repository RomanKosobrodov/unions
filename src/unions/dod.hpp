#pragma once
#include "types.hpp"
#include "vector"

namespace dod
{
    struct shapes
    {
        std::vector<point> origins;
        std::vector<shape_color> colors;
        std::vector<radius> circles;
        std::vector<shape_size> rectangles;

        void reserve(std::size_t n)
        {
            origins.reserve(n);
            colors.reserve(n);
            circles.reserve(n);
            rectangles.reserve(n);
        }
    };
}