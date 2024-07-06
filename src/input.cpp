//
// Created by stewa on 15/06/2024.
//

#include "input.hpp"
#include <SDL.h>
#include <SDL_events.h>

Uint32 Input::Event::trigger()
{
    SDL_Event evt;
    SDL_PollEvent(&evt);

    switch (evt.type)
    {
        case SDL_QUIT:
            return SDL_QUIT;
        case SDL_KEYDOWN:
            return Keyboard::press(evt);
        case SDL_MOUSEBUTTONDOWN:
            return Mouse::click(evt);
        default:
            break;
    }
    return evt.type;
}

Uint32 Input::Keyboard::press(const SDL_Event& evt)
{
    switch (evt.key.keysym.sym)
    {
        case SDLK_ESCAPE:
            return SDL_QUIT;
        default:
            break;
    }
    return 0;
}

Uint32 Input::Mouse::click(const SDL_Event& evt)
{
    switch (evt.button.button) // a button button? SDL enum names are truly marvelous
    {
        case SDL_BUTTON_LEFT:
            break;
        case SDL_BUTTON_RIGHT:
            break;
        default:
            break;
    }
    return 0;
}
