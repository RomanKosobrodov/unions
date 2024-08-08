#pragma once
#include "types.hpp"
#include "vector"

namespace dod
{
    struct shapes
    {
        std::vector<point> origins;
        std::vector<shape_color> colors;
        std::vector<float> radii;
        std::vector<float> sides;

        void reserve(std::size_t n)
        {
            origins.reserve(n);
            colors.reserve(n);
            radii.reserve(n);
            sides.reserve(2 * n);
        }

        void append_circle(const point &p, const shape_color &c, float radius)
        {
            origins.push_back(p);
            colors.push_back(c);
            radii.push_back(radius);
        }

        void append_rectangle(const point &p, const shape_color &c, float a, float b)
        {
            origins.push_back(p);
            colors.push_back(c);
            radii.push_back(a);
            radii.push_back(b);
        }
    };
}