#include "stdafx.h"
#include "GameScene.h"
#include "LockOn2D.h"


LockOn2D::LockOn2D()
{
}


LockOn2D::~LockOn2D()
{
}

void LockOn2D::Init()
{
	lockOn2D.Init("Assets/Model/target.png");
	lockOn2D.Setpos(D3DXVECTOR2(0.0f, 0.0f));
	lockOn2D.Setsize(D3DXVECTOR2(64, 64));
}

void LockOn2D::Update()
{
	if (lockOnEnemy) {
		D3DXVECTOR2 lockOnCursorPos;
		D3DXVECTOR3 enemyCenterPos = lockOnEnemy->Getpos();
		
		game->GetCamera().CalcScreenPositionFromWorldPosition(lockOnCursorPos, enemyCenterPos);
		lockOn2D.Setpos(lockOnCursorPos);
	}
}
void LockOn2D::Render()
{
	if (lockOnEnemy&&lockOnEnemy->GetnowEnemyS() != lockOnEnemy->DEATH)
	{
		D3DXMATRIX identity;
		D3DXMatrixIdentity(&identity);
		lockOn2D.Render(identity, identity);
	}
	
}