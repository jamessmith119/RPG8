#pragma once

#include "GraphicsEngine.h"

class Game
{
	private:
		GraphicsEngine graphicsEngine;

	public:
		bool Initialize();
		void Shutdown();
};