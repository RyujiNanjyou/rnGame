#include "stdafx.h"
#include "CharacterController.h"
#include "GameScene.h"
#include "Enemy.h"
#include "BallCollision.h"
#include "Tama.h"

Tama::Tama()
{
	BaseTama::BaseTama();
}

Tama::~Tama()
{
	
}
void Tama::Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction)
{
	
	BaseTama::Shot(pos,direction);
}

void Tama::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	BaseTama::Init(pd3dDevice, Name);
	life = 25;
}
bool Tama::Update()
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
	
	moveTama += dir * 10.0f;
	position = characterController.GetPosition();
	characterController.SetMoveSpeed(moveTama);
	characterController.Execute();
	return true;
}
void Tama::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	BaseTama::Render(viwe, proj, ShadowFlag);
}