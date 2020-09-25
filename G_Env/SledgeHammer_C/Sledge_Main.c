#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine* engine = Engine_Ignite("T-Slug", 1440, 810, false);
	Engine_InitializeGameSystem(engine);
	Engine_Run(engine);
	Engine_Destroy(engine);
	return EXIT_SUCCESS;
}