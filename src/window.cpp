//
// Created by stewa on 08/06/2024.
//
#include "window.hpp"

bool Window::resize(const int width, const int height)
{
    const bool isValidResizeResolution =
            _width >= WINDOW_DEFAULT_WIDTH &&
            _height >= WINDOW_DEFAULT_HEIGHT &&
            16 * _height == 9 * _width;

    if (isValidResizeResolution && SDL_SetWindowSize(m_sdl.get(), width, height))
    {
        _width = width;
        _height = height;
        return true;
    }
    return false;
}
