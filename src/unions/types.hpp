#pragma once

#include <array>

typedef std::array<char, 4> shape_color;
constexpr shape_color default_color{0, 0, 0, char(255)};

struct point
{
    float x{0};
    float y{0};
};