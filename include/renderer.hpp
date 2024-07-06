//
// Created by stewa on 16/06/2024.
//
#pragma once
#include <window.hpp>

class Renderer
{
public:
    Renderer(const Window& window, const int driver, const int flags) :
                                            m_sdl(SDL_CreateRenderer(window.m_sdl.get(), driver, flags), SDL_DestroyRenderer)
    {

    }
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_sdl;

    void RenderRectangle(const Color color, const int transparency) const;
};
