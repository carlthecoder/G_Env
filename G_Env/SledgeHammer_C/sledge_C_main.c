#include "Engine.h"
#include "RenderSystem.h"
#include "Vector2D.h"

int main(int argc, char* argv[])
{
	Engine* engine = BootEngine("Tank", 1440, 810, false);

	InitializeGameSystem(engine);
	RunEngine(engine);
	DestroyEngine(engine);

	return EXIT_SUCCESS;
}