#include "Engine.h"

static bool InitializeSDL(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL initialztion failed.\n");
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	printf("Engine booted.\n");
	return true;
}

static SDL_Window* CreateWindow(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	return SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

static SDL_Renderer* CreateRenderer(SDL_Window* window)
{
	return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

static bool HandleEvents(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return false;
		}
	}

	return true;
}

static void UpdateEngine(Engine* engine)
{
	UpdateGame(engine->game);
}

static void DrawEngine(Engine* engine)
{
	SDL_RenderClear(engine->renderer);

	DrawGame(engine->game);

	SDL_RenderPresent(engine->renderer);
}

Engine* BootEngine(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen)
{
	Engine* engine = malloc(sizeof(Engine));

	if (!InitializeSDL())
		return NULL;

	engine->window = CreateWindow("Tank", width, height, false);
	if (!engine->window)
		printf("Couldn't create window\n");

	engine->renderer = CreateRenderer(engine->window);
	if (!engine->renderer)
		printf("Couldn't create renderer\n");

	// Setting the clear screen color;
	SDL_SetRenderDrawColor(engine->renderer, 30, 50, 50, 255);

	return engine;
}

void InitializeGameSystem(Engine* engine)
{
	// Create an instance of game struct and store it in  the engine
	engine->game = BootGame(engine->renderer);
	LoadGameContent(engine->game);
}

void RunEngine(Engine* engine)
{
	// Initializing framerate to 60 FPS
	const float frameTime = 1000 / 60;
	double deltaTime = 0;
	Uint64 last = 0;
	Uint64 now = SDL_GetPerformanceCounter();

	// Game loop
	bool running = true;
	while (running)
	{
		last = now;
		{
			running = HandleEvents();
			UpdateEngine(engine);
			DrawEngine(engine);
		}
		now = SDL_GetPerformanceCounter();

		// Enforcing framerate 
		deltaTime = (now - last) * 1000 / (double)SDL_GetPerformanceFrequency();
		if (deltaTime < frameTime)
			SDL_Delay((Uint32)(frameTime - deltaTime));
	}
}

void DestroyEngine(Engine* engine)
{
	// Release and destroy engine objects
	SDL_DestroyWindow(engine->window);
	SDL_DestroyRenderer(engine->renderer);	
	DestroyGame(engine->game);

	// Release the engine object itself
	if (engine)
	{
		free(engine);
		engine = NULL;
		printf("Engine released, set to NULL. ");
	}

	printf("Engine destroyed.\n");
}