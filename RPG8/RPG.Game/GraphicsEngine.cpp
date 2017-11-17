#include "GraphicsEngine.h"

bool GraphicsEngine::Initialize()
{
	bool initialized = false;
	
	direct3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (direct3D)
	{
		initialized = true;
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
