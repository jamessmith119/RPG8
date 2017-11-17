#pragma once

#include<d3d9.h>

class GraphicsEngine
{
	private:
		IDirect3D9 * direct3D = NULL;

	public:
		bool Initialize();
		void Shutdown();
};