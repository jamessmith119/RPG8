#include<Windows.h>
#include"Game.h"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
bool RegisterWindowClass(HINSTANCE);

int WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int cmdShow)
{	
	//Register the main window class
	if (!RegisterWindowClass(instance))
	{
		return false;
	}

	//Create a window
	HWND windowHandle;
	windowHandle = CreateWindow(L"GameClass", L"RPG8", WS_OVERLAPPEDWINDOW, 0, 0, 400, 400, NULL, NULL, instance, NULL);
	if (windowHandle == NULL)
	{
		return false;
	}

	//Show the main window
	ShowWindow(windowHandle, SW_SHOWNORMAL);
	UpdateWindow(windowHandle);

	//Message pump
	MSG message;
	ZeroMemory(&message, sizeof(MSG));

	Game game;
	game.Initialize();

	while (message.message != WM_QUIT)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//TODO
		}
	}

	game.ShutDown();

	UnregisterClass(L"GameClass", instance);

	return 0;
}

LRESULT CALLBACK WindowProcedure(HWND windowHandle, UINT message, WPARAM wParameter, LPARAM lParameter)
{
	switch (message)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(windowHandle, message, wParameter, lParameter);
	}

	return 0;
}

bool RegisterWindowClass(HINSTANCE instance)
{
	WNDCLASSEX mainWindowClass =
	{
		sizeof(mainWindowClass),
		CS_CLASSDC,
		WindowProcedure,
		0,
		0,
		instance,
		NULL,
		NULL,
		NULL,
		NULL,
		L"GameClass",
		NULL
	};

	if (!RegisterClassEx(&mainWindowClass))
	{
		return false;
	}

	return true;
}