#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // This turns the main function in this file into a macro which SDL replaces with WinMain in Windows
#include <iostream>
#include "constants.hpp"
#include "errors.hpp"
#include "input.hpp"
#include "renderer.hpp"
#include "window.hpp"

int main(int argc, char* argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        return Error::InitializingSdl;
    }

    const Window window{Constants::Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080,
                        SDL_WINDOW_VULKAN};
    if (!window.m_sdl)
    {
        return Error::CreatingSdlWindow;
    }

    const Renderer renderer{window};
    if (!renderer.m_sdl)
    {
        return Error::CreatingSdlRenderer;
    }

    while (Input::Event::trigger() != SDL_EVENT_QUIT)
    {
        renderer.RenderRectangle(Colors::GREEN, Transparency::OPAQUE);
    }

    SDL_Quit();
    return 0;
}
