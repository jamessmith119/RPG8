#include "GraphicsEngine.h"

int GraphicsEngine::Initialize()
{
	if (NULL == (direct3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	return 0;
}

void GraphicsEngine::Shutdown()
{
	if (direct3D)
	{
		direct3D->Release();
		direct3D = NULL;
	}
}
