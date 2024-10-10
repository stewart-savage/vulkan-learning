//
// Created by stewa on 08/06/2024.
//
#include "constants.hpp"
#include "window.hpp"

void Window::EnforceDimensions()
{
    // Ensure minimum window size and 16:9 ratio, otherwise use default
    if (_m_width < Constants::WINDOW_MIN_WIDTH || _m_height < Constants::WINDOW_MIN_HEIGHT || (16 * _m_height != 9 * _m_width))
    {
        _m_width = Constants::WINDOW_MIN_WIDTH;
        _m_height = Constants::WINDOW_MIN_HEIGHT;
        SDL_SetWindowSize(m_sdl.get(), _m_width, _m_height);
    }
}
