#include "Game.h"

int Game::Initialize()
{
	if (!graphicsEngine.Initialize())
	{
		return E_FAIL;
	}

	return 0;
}

void Game::Shutdown()
{
	graphicsEngine.Shutdown();
}

//TODO: Remove test code
//int SetupDx()
//{
//	if (NULL == (d3d = Direct3DCreate9(D3D_SDK_VERSION)))
//	{
//		return E_FAIL;
//	}
//
//	D3DDISPLAYMODE mode;
//	mode.Format = D3DFMT_R5G6B5;
//	mode.Height = 480;
//	mode.RefreshRate = 0;
//	mode.Width = 640;
//
//	if (FAILED(d3d->CheckDeviceType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, D3DFMT_R5G6B5, D3DFMT_R5G6B5, FALSE)))
//	{
//		return E_FAIL;
//	}
//
//	if (FAILED(d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode)))
//	{
//		return E_FAIL;
//	}
//}