//
// Created by stewa on 08/06/2024.
//
#include "window.hpp"

bool Window::resize(const int width, const int height)
{
    const bool isValidResizeResolution =
            m_width >= WINDOW_DEFAULT_WIDTH &&
            m_height >= WINDOW_DEFAULT_HEIGHT &&
            16 * m_height == 9 * m_width;

    if (isValidResizeResolution && SDL_SetWindowSize(m_sdl.get(), width, height))
    {
        m_width = width;
        m_height = height;
        return true;
    }
    return false;
}
