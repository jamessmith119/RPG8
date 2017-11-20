#include "GraphicsEngine.h"

bool GraphicsEngine::Initialize()
{
	bool initialized = false;
	
	direct3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3D)
	{
		initialized = true;
	}

	if (FAILED(direct3D->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_R5G6B5, D3DFMT_R5G6B5, FALSE)))
	{
		return E_FAIL;
	}

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
