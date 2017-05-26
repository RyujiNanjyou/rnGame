#include "stdafx.h"
#include "GameScene.h"
#include "EnemyTama.h"


EnemyTama::EnemyTama()
{
	BaseTama::BaseTama();
}

EnemyTama::~EnemyTama()
{

}
void EnemyTama::Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction)
{
	BaseTama::Shot(pos, direction);
}

void EnemyTama::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	BaseTama::Init(pd3dDevice, Name);
	life = 30;
}
bool EnemyTama::Update()
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
void EnemyTama::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	BaseTama::Render(viwe, proj, ShadowFlag);
}