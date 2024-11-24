//
// Created by stewa on 02/06/2024.
//
#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>

static constexpr char WINDOW_TITLE[] = "Application Name Placeholder";
static constexpr int WINDOW_DEFAULT_WIDTH = 1280;
static constexpr int WINDOW_DEFAULT_HEIGHT = 720;

class Window
{
    // No position co-ordinates required. See SDL_CreateWindowWithProperties to define window position using SDL3
    int m_width;
    int m_height;
    uint64_t m_sdl_window_flags;

    // Resize to default window dimensions if _width and _height are not 16:9, or they are smaller than defaults.
    bool resize(int width, int height);

public:
    explicit Window(const int width = WINDOW_DEFAULT_WIDTH, const int height = WINDOW_DEFAULT_HEIGHT,
                    const uint64_t sdlWindowFlags = SDL_WINDOW_VULKAN) : m_width(width), m_height(height),
                                                     m_sdl_window_flags(sdlWindowFlags),
                                                     m_sdl(
                                                         SDL_CreateWindow(WINDOW_TITLE, width, height, sdlWindowFlags),
                                                         SDL_DestroyWindow) {};

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_sdl;
};
