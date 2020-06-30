#pragma once
#include <Windows.h>
#include "GraphicsDevice.h"
#include "WindowException.h"
#include "Keyboard.h"
#include "Mouse.h"

class GameWindow sealed
{
	public:
		Keyboard Keyboard;
		Mouse Mouse;

		GameWindow();
		~GameWindow();
		GameWindow(const GameWindow&) = delete;
		GameWindow& operator=(const GameWindow&) = delete;		

		HWND Create(float positionX, float positionY, float width, float height);
		float GetWidth() const noexcept;
		float GetHeight() const noexcept;
	
	private:
		static constexpr LPCSTR _wndClassName = "GameWindow";
		static int _windowCount;

		HWND _hWnd;
		HINSTANCE _instance;
		float _width;
		float _height;

		static LRESULT CALLBACK WindowProcedureSetup(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
		LRESULT HandleMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
};