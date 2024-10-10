//
// Created by stewa on 15/06/2024.
//

#include "input.hpp"
#include <SDL3/SDL.h>

Uint32 Input::Event::trigger()
{
    SDL_Event evt;
    SDL_PollEvent(&evt);

    switch (evt.type)
    {
        case SDL_EVENT_QUIT:
            return SDL_EVENT_QUIT;
        case SDL_EVENT_KEY_DOWN:
            return Keyboard::press(evt);
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            return Mouse::click(evt);
        default:
            break;
    }
    return evt.type;
}

Uint32 Input::Keyboard::press(const SDL_Event& evt)
{
    switch (evt.key.key)
    {
        case SDLK_ESCAPE:
            return SDL_EVENT_QUIT;
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
