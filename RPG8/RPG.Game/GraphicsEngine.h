#pragma once

#include<d3d9.h>

class GraphicsEngine
{
	private:
		IDirect3D9 * direct3D = NULL;
		IDirect3DDevice9 * device = NULL;
		D3DDISPLAYMODE displayMode = {};

	public:
		bool Initialize();
		HRESULT CheckDisplayMode();
		D3DPRESENT_PARAMETERS InitializeDisplayParameters();
		void Shutdown();
};