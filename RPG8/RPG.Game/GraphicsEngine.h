#pragma once

#include<d3d9.h>

class GraphicsEngine
{
	private:
		LPDIRECT3D9 direct3D;

	public:
		bool Initialize();
		void Shutdown();
};