#include "WinMain.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE previousInstance, LPSTR commandLine, int cmdShow)
{	
	mainWindowHandle = InitializeMainWindow(instance);
	if (mainWindowHandle == NULL)
	{
		MessageBox(NULL, L"Unable to create game window.", L"Fatal Error", MB_ICONERROR);
		return E_FAIL;
	}

	if (!game.Initialize(mainWindowHandle))
	{
		MessageBox(NULL, L"Unable to initialize game.", L"Fatal Error", MB_ICONERROR);
		return E_FAIL;
	}

	RunMessagePump();
	Shutdown(instance);

	return 0;
}

HWND InitializeMainWindow(HINSTANCE instance)
{
	//Register the main window class
	if (!RegisterWindowClass(instance))
	{
		return false;
	}

	//Create a window
	HWND windowHandle = CreateWindow(L"GameClass", L"RPG8", WS_OVERLAPPEDWINDOW, 0, 0, 400, 400, NULL, NULL, instance, NULL);
	if (windowHandle == NULL)
	{
		return false;
	}

	//Show the main window
	ShowWindow(windowHandle, SW_SHOWNORMAL);
	UpdateWindow(windowHandle);

	return windowHandle;
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

void RunMessagePump()
{
	//Message pump
	MSG message;
	ZeroMemory(&message, sizeof(MSG));
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
}

void Shutdown(HINSTANCE instance)
{
	UnregisterClass(L"GameClass", instance);
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