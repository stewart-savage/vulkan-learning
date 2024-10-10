//
// Created by stewa on 06/06/2024.
//
#pragma once
#include <string>
#include "color.hpp"

namespace Constants
{
    const std::string Title("Title");
    constexpr int WINDOW_MIN_WIDTH = 800;
    constexpr int WINDOW_MIN_HEIGHT = 600;
    constexpr int RENDERER_FLAG = 0; // See SDL_RendererFlags for available options
} // namespace Constants

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
