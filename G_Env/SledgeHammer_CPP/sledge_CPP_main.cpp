#include "Engine.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

#undef main

int windowWidth = 1400;
int windowHeight = 900;
SDL_Renderer* renderer = NULL;

void RunGameLoop();

int main()
{
    // Initialize SDL System
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL initialization failed.. | %s\n", SDL_GetError();
        return EXIT_FAILURE;
    }

    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
    {
        std::cout << "SDL_image initialization failed.. | %s\n", IMG_GetError();
    }

    // Initializing the window and the renderer
    SDL_Window* window = InitializeWindow("CGix", windowWidth, windowHeight, 0);
    if (!window)
    {
        std::cout << "The window could not be created.. | %s\n", SDL_GetError();
        return EXIT_FAILURE;
    }

    renderer = InitializeRenderer(window);
    if (!renderer)
    {
        std::cout << "The renderer could not be created.. | %s\n", SDL_GetError();
        return EXIT_FAILURE;
    }

    // Sets the basic background color of the renderer
    SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
    SDL_ShowCursor(SDL_DISABLE);    

    RunGameLoop();

    DestroyEngine(window, renderer);
    return EXIT_SUCCESS;
}

void RunGameLoop()
{
    // Creating the game object;
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->Initialize();

    // FPS Counter
    const float frameTime = 1000 / 60;
    double deltaTime = 0;
    Uint64 last = 0;
    Uint64 now = SDL_GetPerformanceCounter();

    // Start of game loop
    bool running = true;
    while (running)
    {
        last = now;
        {
            running = HandleEvents();
            Update(*game);
            Draw(renderer, *game);
        }
        now = SDL_GetPerformanceCounter();
        deltaTime = (now - last) * 1000 / (double)SDL_GetPerformanceFrequency();

        if (deltaTime < frameTime)
        {
            SDL_Delay((Uint32)(frameTime - deltaTime));
        }
    }
}