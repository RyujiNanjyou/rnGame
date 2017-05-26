#include "stdafx.h"
#include "Texture.h"

bool Texture::Load(const char* fileName, bool isCubeMap)
{
	Release();
	LPDIRECT3DDEVICE9 device = g_pd3dDevice;
	if (!isCubeMap) {
		if (FAILED(D3DXCreateTextureFromFile(
			device,
			fileName,
			&tex))) {
			return false;
		}
	}
	ComputeTexSize();
	return true;
}


