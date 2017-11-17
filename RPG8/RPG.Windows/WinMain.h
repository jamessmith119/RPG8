#pragma once

#include<Windows.h>
#include "Game.h"

HWND mainWindowHandle;
Game game;

bool InitializeMainWindow(HINSTANCE, HWND);
bool RegisterWindowClass(HINSTANCE);
void RunMessagePump();
void Shutdown(HINSTANCE);
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);