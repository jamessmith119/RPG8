#include "GraphicsEngine.h"

bool GraphicsEngine::Initialize()
{
	bool initialized = false;

	direct3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3D)
	{
		if (FAILED(CheckDisplayMode()))
		{
			//TODO: Exception
			return false;
		}

		D3DPRESENT_PARAMETERS displayParameters = InitializeDisplayParameters();
		if (FAILED(direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, NULL, 
			D3DCREATE_SOFTWARE_VERTEXPROCESSING, &displayParameters, &device)))
		{
			//TODO: Exception
			return false;
		}

		initialized = true;
	}	

	return initialized;
}

HRESULT GraphicsEngine::CheckDisplayMode()
{
	HRESULT result = E_FAIL;
	result = direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode);
	result = direct3D->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, displayMode.Format, displayMode.Format, FALSE);

	return result;
}

D3DPRESENT_PARAMETERS GraphicsEngine::InitializeDisplayParameters()
{
	D3DPRESENT_PARAMETERS displayParameters = {};
	displayParameters.BackBufferFormat = displayMode.Format;
	displayParameters.BackBufferHeight = displayMode.Height;
	displayParameters.BackBufferWidth = displayMode.Width;
	displayParameters.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	displayParameters.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
	displayParameters.SwapEffect = D3DSWAPEFFECT_FLIP;
	displayParameters.Windowed = FALSE;

	return displayParameters;
}

void GraphicsEngine::Shutdown()
{
	if (direct3D)
	{
		direct3D->Release();
		direct3D = NULL;
	}
}
