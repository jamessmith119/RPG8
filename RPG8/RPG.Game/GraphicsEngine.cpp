#include "GraphicsEngine.h"

bool GraphicsEngine::Initialize()
{
	bool initialized = false;
	
	direct3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3D)
	{
		initialized = true;
	}

	D3DDISPLAYMODE displayMode = {};
	if (FAILED(direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode)))
	{
		return E_FAIL;
	}

	if (FAILED(direct3D->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, displayMode.Format, displayMode.Format, FALSE)))
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS displayParameters = {};
	displayParameters.BackBufferFormat = displayMode.Format;
	displayParameters.BackBufferHeight = displayMode.Height;
	displayParameters.BackBufferWidth = displayMode.Width;
	displayParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	displayParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
	displayParameters.SwapEffect = D3DSWAPEFFECT_FLIP;
	displayParameters.Windowed = FALSE;

	return initialized;
}

void GraphicsEngine::Shutdown()
{
	if (direct3D)
	{
		direct3D->Release();
		direct3D = NULL;
	}
}
