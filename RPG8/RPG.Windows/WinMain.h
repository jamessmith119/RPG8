#pragma once

#include<Windows.h>
#include "Game.h"

HWND mainWindowHandle;
Game game;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
bool RegisterWindowClass(HINSTANCE);