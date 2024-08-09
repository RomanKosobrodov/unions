#pragma once
#include "types.hpp"

namespace tu
{
    struct circle_shape
    {
        float radius{1.0f};
    };

    struct rectangle_shape
    {
        float a{1.0f};
        float b{1.0f};
    };

    enum class shape_tag
    {
        none,
        circle,
        rectangle
    };

    struct shape
    {
        point origin;
        shape_color color{default_color};
        shape_tag tag{shape_tag::none};
        union
        {
            circle_shape circle;
            rectangle_shape rectangle;
        };

        shape(const point &xy, const shape_color &c, float r)
            : origin{xy.x, xy.y}, color{c}, tag{shape_tag::circle}, circle{r}
        {
        }

        shape(const point &xy, const shape_color &c, float a, float b)
            : origin{xy.x, xy.y}, color{c}, tag{shape_tag::rectangle}, rectangle{a, b}
        {
        }
    };

    inline float area(const circle_shape &c) { return 3.1415926535f * c.radius * c.radius; }
    inline float area(const rectangle_shape &r) { return r.a * r.b; }

    inline float area(const shape &s)
    {
        switch (s.tag)
        {
        case shape_tag::circle:
            return area(s.circle);
            break;
        case shape_tag::rectangle:
            return area(s.rectangle);
            break;
        default:
            break;
        }
        return 0;
    }
}