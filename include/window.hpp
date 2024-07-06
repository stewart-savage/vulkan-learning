//
// Created by stewa on 02/06/2024.
//
#pragma once
#include <iostream>
#include <memory>
#include <SDL.h>
#include <SDL_video.h>
#include <string>
#include "constants.hpp"


class Window
{
    const std::string _m_title;
    int _m_xpos;
    int _m_ypos;
    int _m_width;
    int _m_height;
    uint32_t _m_sdlWindowFlags;


    void EnforceDimensions();

public:
    Window(std::string title, const int xpos, const int ypos, const int width, const int height,
           const uint32_t sdlWindowFlags) : _m_title(std::move(title)),
                                            _m_xpos(xpos),
                                            _m_ypos(ypos),
                                            _m_width(width),
                                            _m_height(height),
                                            _m_sdlWindowFlags(sdlWindowFlags),
                                            m_sdl(SDL_CreateWindow(_m_title.c_str(), xpos, ypos, width, height,
                                                                   sdlWindowFlags), SDL_DestroyWindow)

    {
        if (m_sdl)
        {
            EnforceDimensions();
        }
    }

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_sdl;
};
