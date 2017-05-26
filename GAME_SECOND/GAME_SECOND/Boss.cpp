#include "stdafx.h"
#include "GameScene.h"
#include "BallCollision.h"
#include "Boss.h"

namespace
{
	const D3DXVECTOR3 Zero(0.0f, 0.0f, 0.0f);
	float angle = 0;
}
Boss::Boss()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

}


Boss::~Boss()
{

}

void Boss::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	GameObject::Init(pd3dDevice, Name);
	position = D3DXVECTOR3(121.175f, -1.54f, 0.00f);
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	nowbossS = NowBossState::BossSTATE_IDOL;
	D3DXVECTOR3 pos = position;
	characterController.Init(radius, height, pos);
	characterController.SetGravity(-20.0f);	//d—Í‹­‚ßB
}
void Boss::Damage()
{
	for (auto tama : game->GetPlayerTama())
	{
		if (BallCollision(position, tama->Getpos(), radius, 0.5))
		{
			if (intervalDamageTime == 0)
			{
				hp -= 1;
				intervalDamageTime = 5;
			}
			intervalDamageTime--;
			if (intervalDamageTime < 0.0f)
			{
				intervalDamageTime = 0;
			}
		}
	}
	if (hp <= 0.0f)
	{
		hp = 0;
		characterController.RemoveRigidBoby();
		comp = true;
		nowbossS = NowBossState::BossSTATE_DEAD;
		Drawflag = true;
	}
	if (nowbossS == NowBossState::BossSTATE_DEAD)
	{	
		SoundSource* se = new SoundSource;
		se->Init("Assets/Sound/bomb.wav");
		se->Play(false);
		se->SetVolume(5.0f);
	}
}

bool Boss::Update()
{

	position = characterController.GetPosition();
	D3DXVECTOR3 moveSpeed = characterController.GetMoveSpeed();
	moveSpeed.x = Zero.x;
	moveSpeed.z = Zero.y;
	D3DXVECTOR3 to = game->GetPlayer()->Getpos() - position;
	to.y = 0.0f;
	float len = D3DXVec3Length(&to);
	Damage();
	if (comp == false)
	{
		if (len < 5.0f)
		{
			moveSpeed = to * 0.7f;
			if (intervalTime == 0)
			{
				BossTama* tama = new BossTama();
				D3DXVECTOR3 pos = position;
				pos.y += 0.5;
				D3DXVECTOR3 dir(1.0f, 0.0f, 0.0f);
				angle += PI / 5;
				dir.x = cos(angle);
				dir.z = sin(angle);
				tama->Shot(pos, dir);
				tama->Init(g_pd3dDevice, "Assets/Model/tama");
				game->AddBossTama(tama);

				SoundSource* se = new SoundSource;
				se->Init("Assets/Sound/beam-gun01.wav");
				se->Play(false);
				se->SetVolume(0.1f);
				intervalTime = 7;
			}
			intervalTime--;
			if (intervalTime <= 0)
			{
				intervalTime = 0;
			}
		}

	}
	
	characterController.SetMoveSpeed(moveSpeed);
	characterController.Execute();
	position.y += 0.5f;
	GameObject::Update();
	return true;
}