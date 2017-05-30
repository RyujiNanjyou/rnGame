#include "stdafx.h"
#include "GameObject.h"
#include "GameScene.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Init(LPDIRECT3DDEVICE9 pd3dDevice, SkinModelData* modelData)
{
	skinmodel.Init(modelData);
	skinmodel.SetLight(game->GETlight());
	skinmodel.SetEffect(effectmanager->LoadEffect("Assets/Shader/Model.fx"));
	//シェーダーをコンパイル。
	LPD3DXBUFFER  compileErrorBuffer = NULL;

	Drawflag = false;
}
void GameObject::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name){

	char modelPath[256];
	sprintf(modelPath, "%s.X", Name);
	//まずはスキンモデルをロード。
	skinmodeldata.LoadModelData(modelPath, &anim);
	Init(pd3dDevice, &skinmodeldata);
	
}
bool GameObject::Update()
{
	skinmodel.UpdateWorldMatrix(position, rotation, scale);
	return true;
}
void GameObject::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	if (Drawflag == false)
	{
		skinmodel.Draw(
			&viwe,
			&proj,
			ShadowFlag
			);
	}
}
void GameObject::Release()
{
	
	
}