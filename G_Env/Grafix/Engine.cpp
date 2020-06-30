#include "Engine.h"

Engine::Engine()
	:
	windowWidth(400),
	windowHeight(300),
	windowPositionX(50),
	windowPositionY(50),
	keyboard(gameWindow.Keyboard),
	mouse(gameWindow.Mouse)
{}

void Engine::Initialize()
{
	HWND hwnd = gameWindow.Create(windowPositionX, windowPositionY, windowWidth, windowHeight);
	graphicsDevice.Initialize(hwnd, windowWidth, windowHeight);
}

void Engine::Run()
{
	MSG msg;

	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		ProcessFrame();
		graphicsDevice.PresentFrame();
	}

	graphicsDevice.CleanD3D();
}
void Engine::ProcessFrame()
{
	Update();
	Draw();	
}