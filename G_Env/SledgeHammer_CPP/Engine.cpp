#include "Engine.h"
#include <stdio.h>

SDL_Window* InitializeWindow(const char title[], int width, int height, int fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        width = 1920;
        height = 1080;
        flags = SDL_WINDOW_FULLSCREEN;
    }

    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    return window;
}

SDL_Renderer* InitializeRenderer(SDL_Window* window)
{
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    return renderer;
}

int HandleEvents()
{
    SDL_Event event = {};

    while (SDL_PollEvent(&event) > 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
                return 0;
        }
    }

    return 1;
}

void Update(Game& game)
{
    game.Update();
}

void Draw(SDL_Renderer* renderer, Game& game)
{
    SDL_RenderClear(renderer);

    game.Draw();

    SDL_RenderPresent(renderer);
}

void DestroyEngine(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    printf("Window destroyed...\nRenderer destroyed..");
}