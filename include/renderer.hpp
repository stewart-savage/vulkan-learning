//
// Created by stewa on 16/06/2024.
//
#pragma once
#include <color.hpp>
#include <window.hpp>

class Renderer
{
    const char* renderingDriver = nullptr; // This determines which GPU to use, null uses default device.
public:
    explicit Renderer(const Window& window) :
        m_sdl(SDL_CreateRenderer(window.m_sdl.get(), renderingDriver), SDL_DestroyRenderer)
    {}
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_sdl;

    void RenderRectangle(Color color, int transparency) const;
};
