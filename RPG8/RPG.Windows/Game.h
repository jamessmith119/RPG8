#pragma once

#include "GraphicsEngine.h"

class Game
{
	private:
		GraphicsEngine graphicsEngine;
		HWND gameWindow;
	public:
		~Game();
		bool Initialize(HWND);
		void Shutdown();
};