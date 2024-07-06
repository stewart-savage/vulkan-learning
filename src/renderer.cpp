//
// Created by stewa on 16/06/2024.
//

#include "renderer.hpp"

// kinda basic render test to change background of window
void Renderer::RenderRectangle(const Color color, const int transparency) const
{
    SDL_SetRenderDrawColor(m_sdl.get(), color.r, color.g, color.b, transparency);
    SDL_RenderClear(m_sdl.get());
    SDL_RenderPresent(m_sdl.get());
}
