#include <expected>
#include <iostream>
#include <glm/glm.hpp>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // This turns the main function in this file into a macro which SDL replaces with WinMain in Windows
#include <vulkan/vulkan_core.h>

#include "app.hpp"

int main(int, char*[])
{
    if (auto result = App::run(); !result.has_value())
    {
        std::cerr << result.error();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
