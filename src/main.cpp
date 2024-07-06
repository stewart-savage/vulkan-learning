#include <iostream>
#include <SDL.h>
#include "constants.hpp"
#include "errors.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "window.hpp"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        return Error::InitializingSdl;
    }

    const Window window{Constants::Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_VULKAN};
    if (!window.m_sdl)
    {
        return Error::CreatingSdlWindow;
    }

    const Renderer renderer{window, Constants::RENDERER_DRIVER, Constants::RENDERER_FLAG};
    if (!renderer.m_sdl)
    {
        return Error::CreatingSdlRenderer;
    }

    while (Input::Event::trigger() != SDL_QUIT)
    {
        renderer.RenderRectangle(Colors::GREEN, Transparency::OPAQUE);
    }

    SDL_Quit();
    return 0;
}
