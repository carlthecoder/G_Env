#include "Engine.h"
#include <SDL.h>
#undef main			// SDL.h defines a main macro
#include <memory>



int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	std::unique_ptr<Engine> engine = std::make_unique<Engine>();

	engine->Init("The Quest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1400, 900, false);

	constexpr float FPS = 60;
	constexpr float frameTime = 1000 / 60;
	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	double deltaTime = 0;

	while (engine->IsRunning())
	{
		last = now;

		engine->HandleEvents();
		engine->Update();
		engine->Render();

		now = SDL_GetPerformanceCounter();
		deltaTime = (double)((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());

		if (deltaTime < frameTime)
		{
			SDL_Delay(static_cast<Uint32>(frameTime - deltaTime));
		}
	}

	engine->Clean();

	return 0;
}