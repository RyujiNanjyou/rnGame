#include "stdafx.h" 
#include "GameScene.h"
#include "SkyBox.h"

namespace
{
	D3DXQUATERNION rot(0.0f, 0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 scale(1.0f, 1.0f, 1.0f);
}
SkyBox::SkyBox()
{
}


SkyBox::~SkyBox()
{
}

void SkyBox::Init()
{
	skinmodeldata.LoadModelData("Assets/Model/Sky.x", NULL);
	skinmodel.Init(&skinmodeldata);
	light.Setamb(D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f));
	light.SetDLColor(0, D3DXVECTOR4(0, 0, 0, 0));
	light.SetDLColor(1, D3DXVECTOR4(0, 0, 0, 0));
	light.SetDLColor(2, D3DXVECTOR4(0, 0, 0, 0));
	light.SetDLColor(3, D3DXVECTOR4(0, 0, 0, 0));
	skinmodel.SetLight(&light);
	skinmodel.SetEffect(effectmanager->LoadEffect("Assets/Shader/Model.fx"));

}

void SkyBox::Update()
{
	D3DXVECTOR3 look = game->GetGameCamera().GetCamera().GetLookatPt();
	look.y = -60.0f;
	skinmodel.UpdateWorldMatrix(look, rot, scale);
}

void SkyBox::Render()
{
	skinmodel.Draw(&game->GetGameCamera().GetCamera().GetViewMatrix(), &game->GetGameCamera().GetCamera().GetProjectionMatrix(), false);
}