#pragma once

#include<d3d9.h>

class GraphicsEngine
{
	private:
		IDirect3D9 * direct3D = NULL;
		IDirect3DDevice9 * device = NULL;
		D3DDISPLAYMODE displayMode = {};
		HWND targetWindow;

	public:
		bool Initialize(HWND);
		HRESULT CheckDisplayMode();
		D3DPRESENT_PARAMETERS InitializeDisplayParameters();
		void Shutdown();
};