#include "GameWindow.h"

int GameWindow::_windowCount = 0;

GameWindow::GameWindow()
	:
	_instance(GetModuleHandle(nullptr))
{}

GameWindow::~GameWindow()
{
	UnregisterClass(_wndClassName, _instance);
	DestroyWindow(_hWnd);
}

HWND GameWindow::Create(float positionX, float positionY, float width, float height)
{
	_width = width;
	_height = height;

	// Create and register the window class
	WNDCLASSEX wc = { 0 };
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpfnWndProc = WindowProcedureSetup;
	wc.hInstance = _instance;
	wc.lpszClassName = _wndClassName;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&wc);

	// Adjust the window
	RECT windowRect = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	// Create and get a handle to the window
	_hWnd = CreateWindowEx(
		NULL,
		_wndClassName,
		"Game Window",
		WS_OVERLAPPEDWINDOW,
		positionX, positionY,
		windowRect.right - windowRect.left,
		windowRect.bottom - windowRect.top,
		nullptr,
		nullptr,
		_instance,
		this);

	if (_hWnd == nullptr)
	{
		throw WindowException(__LINE__, __FILE__);
	}	
	
	ShowWindow(_hWnd, SHOW_OPENWINDOW);
	_windowCount++;

	return _hWnd;
}

float GameWindow::GetWidth() const noexcept
{
	return _width;
}

float GameWindow::GetHeight() const noexcept
{
	return _height;
}

LRESULT CALLBACK GameWindow::WindowProcedureSetup(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	if (msg == WM_NCCREATE)
	{
		// USE CREATESTRUCT TO GET THE POINTER TO THE POINTER OF THE WINDOW
		const CREATESTRUCTW* const pCreateStruct = reinterpret_cast<CREATESTRUCTW*>(lparam);
		GameWindow* const pGameWindow = static_cast<GameWindow*>(pCreateStruct->lpCreateParams);

		//SET THE LONGPOINTER FOR THE WINDOW SO THAT IT IS ASSOCIATED WITH THE CLASS
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pGameWindow));
		SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&GameWindow::WindowProcedure));

		return pGameWindow->HandleMessage(hwnd, msg, wparam, lparam);		
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}

LRESULT CALLBACK GameWindow::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	auto gameWindow = reinterpret_cast<GameWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));	
	return gameWindow->HandleMessage(hwnd, msg, wparam, lparam);	
}

LRESULT GameWindow::HandleMessage(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
		case WM_CLOSE:
			CloseWindow(_hWnd);

			if (--_windowCount == 0)
			{
				PostQuitMessage(0);
				return 0;
			}
			break;

		//*****  KEYBOARD MESSAGES  *****//
		//*******************************//
		case WM_KILLFOCUS:
			Keyboard.ClearState();
			break;

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			if (!(lparam & 0x40000000) || Keyboard.AutoRepeatIsEnabled())
			{
				Keyboard.OnKeyDownMessageReceived(static_cast<unsigned char>(wparam));
			}
			break;

		case WM_KEYUP:
			Keyboard.OnKeyUpMessageReceived(static_cast<unsigned char>(wparam));
			break;

		case WM_CHAR:
			Keyboard.OnCharMessageReceived(static_cast<unsigned int>(wparam));
			break;

		//***** MOUSE MESSAGES *****//
		//**************************//
		case WM_MOUSEMOVE:
		{
			const POINTS pt = MAKEPOINTS(lparam);

			if (pt.x >= 0 && pt.x < _width && pt.y >= 0 && pt.y < _height)
			{
				Mouse.OnMouseMove(pt.x, pt.y);

				if (!Mouse.IsInWindow())
				{
					SetCapture(_hWnd);
					Mouse.OnMouseEnter();
				}
			}
			else
			{
				if (wparam & (MK_LBUTTON | MK_RBUTTON))
				{
					Mouse.OnMouseMove(pt.x, pt.y);
				}
				else
				{
				}
				{
					ReleaseCapture();
					Mouse.OnMouseLeave();
				}
			}
			break;
		}
		case WM_LBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lparam);
			Mouse.OnLeftPressed(pt.x, pt.y);
			break;
		}
		case WM_LBUTTONUP:
		{
			const POINTS pt = MAKEPOINTS(lparam);
			Mouse.OnLeftReleased(pt.x, pt.y);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			const POINTS pt = MAKEPOINTS(lparam);
			Mouse.OnRightPressed(pt.x, pt.y);
			break;
		}
		case WM_RBUTTONUP:
		{
			const POINTS pt = MAKEPOINTS(lparam);
			Mouse.OnRightReleased(pt.x, pt.y);
			break;
		}
		case WM_MOUSEWHEEL:
		{
			const POINTS pt = MAKEPOINTS(lparam);
			const int delta = GET_WHEEL_DELTA_WPARAM(wparam);
			Mouse.OnWheelDelta(pt.x, pt.y, delta);
			break;
		}
	}

	return DefWindowProc(hwnd, msg, wparam, lparam);
}