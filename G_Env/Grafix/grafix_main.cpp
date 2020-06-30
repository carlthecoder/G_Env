#include <Windows.h>
#include "Game.h"
#include "Exception.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR cmdLine, int cmdShow)
{
	try
	{
		Game game;
		game.Initialize();
		game.Run();		
	}
	catch (const Exception& e)
	{
		MessageBox(nullptr, e.what(), e.GetType(), MB_ICONERROR);
	}
	catch (const std::exception& e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_ICONERROR);
	}
	catch (...)
	{
		MessageBox(nullptr, "An undefined exception has been thrown!", "Unknown Exception", MB_ICONERROR);
	}	
	
	return -1;
}