#include "stdafx.h"
#include "GameScene.h"
#include "BossTama.h"


BossTama::BossTama()
{
	BaseTama::BaseTama();
}

BossTama::~BossTama()
{

}
void BossTama::Shot(const D3DXVECTOR3& pos, const D3DXVECTOR3& direction)
{
	BaseTama::Shot(pos, direction);
}

void BossTama::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	BaseTama::Init(pd3dDevice, Name);
	life = 100;
}
bool BossTama::Update()
{
	
	D3DXVECTOR3 moveTama = characterController.GetMoveSpeed();
	moveTama.x = 0.0f;
	moveTama.z = 0.0f;
	life--;
	if (life < 0)
	{
		characterController.RemoveRigidBoby();
		return false;
	}
	else if (characterController.IsKabe())
	{
		characterController.RemoveRigidBoby();
		return false;
	}
	else if (game->GetPlayer()->GetisDamage() == true)
	{
		characterController.RemoveRigidBoby();
		return false;
	}
	moveTama += dir * 10.0f;
	position = characterController.GetPosition();
	characterController.SetMoveSpeed(moveTama);
	characterController.Execute();
	return true;
}
void BossTama::Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass)
{
	BaseTama::Render(viwe, proj, ShadowFlag,isZPrepass);
}