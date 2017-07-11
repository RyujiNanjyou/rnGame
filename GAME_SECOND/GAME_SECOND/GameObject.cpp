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
void GameObject::Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag,bool isZPrepass)
{
	if (Drawflag == false)
	{
		skinmodel.Draw(
			viwe,
			proj,
			ShadowFlag,
			isZPrepass
			);
	}
}
void GameObject::Release()
{
	
	
}