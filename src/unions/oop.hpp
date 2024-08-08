#pragma once

#include "types.hpp"

namespace oop
{
    struct basic_shape
    {
        point origin;
        shape_color color{default_color};
        basic_shape(const point &o, const shape_color &c)
            : origin{o}, color{c}
        {
        }
        virtual float area() const { return 0; }
        virtual ~basic_shape() = default;
    };

    struct circle : public basic_shape
    {
        float radius{0};
        circle(const point &o, const shape_color &c, float r)
            : basic_shape{o, c}, radius{r}
        {
        }
        float area() const override final { return 3.1415926535f * radius * radius; }
    };

    struct rectangle : public basic_shape
    {
        float a{0};
        float b{0};
        rectangle(const point &o, const shape_color &c, float side_a, float side_b)
            : basic_shape{o, c}, a{side_a}, b{side_b}
        {
        }
        float area() const override final { return a * b; }
    };
};