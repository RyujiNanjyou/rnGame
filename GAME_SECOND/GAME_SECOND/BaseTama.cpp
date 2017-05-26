#include "stdafx.h"
#include "BaseTama.h"

namespace{
	SkinModelData originalModelData;
	bool isLoadedOriginalModelData = false;
}

BaseTama::BaseTama()
{
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	dir = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

BaseTama::~BaseTama()
{

}
void BaseTama::Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction)
{

	position = pos;
	dir = direction;
}

void BaseTama::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	if (isLoadedOriginalModelData == false){
		//モデルのロードがまだ。
		char modelPath[256];
		sprintf(modelPath, "%s.X", Name);
		originalModelData.LoadModelData(modelPath, NULL);
		isLoadedOriginalModelData = true;
	}
	GameObject::Init(pd3dDevice, &originalModelData);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 pos = position;
	characterController.Init(radius, height, pos);
	characterController.SetGravity(0.0f);
}
void BaseTama::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	GameObject::Update();
	GameObject::Render(viwe, proj, ShadowFlag);
}