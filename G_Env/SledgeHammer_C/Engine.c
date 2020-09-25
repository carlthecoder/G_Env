#include "Engine.h"

static bool Engine_InitializeSDL(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL initialztion failed.\n");
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	printf("SDL Initialized.\n");
	return true;
}

static SDL_Window* Engine_CreateSDLWindow(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;

		// todo: Reset the height and with the the fullscreen resolution
		// might need a win32 call here to find the screen resolutions
	}

	return SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
}

static bool Engine_HandleEvents(void)
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

static void Engine_Update(Engine* engine)
{
	Game_Update(engine->game);
}

static void Engine_Draw(Engine* engine)
{
	SDL_RenderClear(engine->renderer);

	Game_Draw(engine->game);

	SDL_RenderPresent(engine->renderer);
}

Engine* Engine_Ignite(char* windowTitle, uint16_t width, uint16_t height, bool fullscreen)
{
	if (!Engine_InitializeSDL())
		return NULL;

	Engine* engine = malloc(sizeof(Engine));

	if (engine)
	{
		engine->window = Engine_CreateSDLWindow(windowTitle, width, height, false);

		if (engine->window)
		{
			engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);

			if (engine->renderer)
				SDL_SetRenderDrawColor(engine->renderer, 30, 50, 50, 255);
			else
				printf("Couldn't create renderer\n");
		}
		else
			printf("Couldn't create window\n");
	}	

	return engine;
}

void Engine_InitializeGameSystem(Engine* engine)
{
	engine->game = Game_Startup(engine->renderer);
	Game_LoadContent(engine->game);
}

void Engine_Run(Engine* engine)
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
			running = Engine_HandleEvents();
			Engine_Update(engine);
			Engine_Draw(engine);
		}
		now = SDL_GetPerformanceCounter();

		// Enforcing framerate 
		deltaTime = (now - last) * 1000 / (double)SDL_GetPerformanceFrequency();
		if (deltaTime < frameTime)
			SDL_Delay((Uint32)(frameTime - deltaTime));
	}
}

void Engine_Destroy(Engine* engine)
{
	// Release and destroy engine objects
	Game_Destroy(engine->game);
	SDL_DestroyRenderer(engine->renderer);	
	SDL_DestroyWindow(engine->window);

	// Release the engine object itself	
	free(engine);
	engine = NULL;
	printf("Engine destroyed.\n");
}