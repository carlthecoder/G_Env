#pragma once
#include "GameWindow.h"
#include "GraphicsDevice.h"
#include "Keyboard.h"
#include "Mouse.h"

class Engine
{
	public:
		Engine();		
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		
		virtual void Initialize();
		virtual void Update() = 0;
		virtual void Draw() = 0;
		void Run();

	protected:
		GameWindow gameWindow;
		GraphicsDevice graphicsDevice;
		Keyboard& keyboard;
		Mouse& mouse;

		float windowWidth;
		float windowHeight;
		float windowPositionX;
		float windowPositionY;

	private:
		void ProcessFrame();
};