//
// Created by stewa on 06/06/2024.
//
#pragma once
#include "color.hpp"

namespace Colors
{
    constexpr Color RED{255, 0, 0};
    constexpr Color GREEN{0, 255, 0};
    constexpr Color BLUE{0, 0, 255};
} // namespace Colors

namespace Transparency
{
    constexpr int OPAQUE = 255;
    constexpr int HALF = 128;
    constexpr int FULL = 0;
} // namespace Transparency
