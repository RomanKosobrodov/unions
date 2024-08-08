#pragma once
#include <variant>
#include "types.hpp"

namespace v
{
    struct circle
    {
        point origin;
        shape_color color{default_color};
        float radius{0};
    };
    struct rectangle
    {
        point origin;
        shape_color color{default_color};
        float a{0};
        float b{0};
    };

    using shape = std::variant<circle, rectangle>;

    inline float area(const circle &c) { return 3.1415926535f * c.radius * c.radius; }
    inline float area(const rectangle &r) { return r.a * r.b; }

}