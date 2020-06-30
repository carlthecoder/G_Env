#pragma once
#include "Engine.h"

class Game : public Engine
{
	public:
		Game();
		~Game();

		virtual void LoadContent();
		virtual void UnloadContent();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw() override;
};