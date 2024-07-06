//
// Created by stewa on 06/06/2024.
//
#pragma once
#include <string>
#include "color.hpp"

namespace Constants
{
    const std::string Title ("Title");
    constexpr int WINDOW_MIN_WIDTH = 800;
    constexpr int WINDOW_MIN_HEIGHT = 600;
    constexpr int RENDERER_DRIVER = -1; // Defaults to use first driver that can render, such as the default GPU
    constexpr int RENDERER_FLAG = 0; // See SDL_RendererFlags for available options
}

namespace Colors // American spelling :(
{
    constexpr Color RED{255, 0, 0};
    constexpr Color GREEN{0, 255, 0};
    constexpr Color BLUE{0, 0, 255};
}

namespace Transparency
{
    constexpr int OPAQUE = 255;
    constexpr int HALF = 128;
    constexpr int FULL = 0;
}