#pragma once

#include "GraphicsEngine.h"

class Game
{
	private:
		GraphicsEngine graphicsEngine;

	public:
		int Initialize();
		void Shutdown();
};