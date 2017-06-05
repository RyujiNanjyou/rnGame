#include "stdafx.h"
#include "GameScene.h"
#include "BallCollision.h"
#include "Boss.h"

namespace
{
	const D3DXVECTOR3 Zero(0.0f, 0.0f, 0.0f);
	const D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);
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
	Release();
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
				if (hp <= 0.0f)
				{
					hp = 0;
					nowbossS = NowBossState::BossSTATE_DEAD;

				}
				else
				{
					renderflag = true;
				}
				intervalDamageTime = 5;
			}
			intervalDamageTime--;
			if (intervalDamageTime < 0.0f)
			{
				intervalDamageTime = 0;
			}
		}
	}	
	
	if (nowbossS == NowBossState::BossSTATE_DEAD)
	{	
		/*deathse.reset(new SoundSource);
		deathse->Init("Assets/Sound/bomb.wav");
		deathse->Play(false);
		deathse->SetVolume(0.8f);*/
		Drawflag = true;
		characterController.RemoveRigidBoby();
		comp = true;
		num += deltaTime;
		if (num > 1.0f)
		{
			scenemanager->ChangeScene(scenemanager->TITLE);
		}
	}
}
void Boss::Attackshot()
{
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

		bossAttackse.reset(new SoundSource);
		bossAttackse->Init("Assets/Sound/beam-gun01.wav");
		bossAttackse->Play(false);
		bossAttackse->SetVolume(0.1f);
		intervalTime = 7;
	}
	intervalTime--;
	if (intervalTime <= 0)
	{
		intervalTime = 0;
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
			rotation = SetRotation(Up, atan2f(to.x, to.z));
			Attackshot();
		}
	}
	characterController.SetMoveSpeed(moveSpeed);
	characterController.Execute();
	position.y += 0.5f;
	GameObject::Update();
	return true;
}
void Boss::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	if (renderflag == true)
	{
		if (damageTime == 0)
		{
			GameObject::Render(viwe, proj, ShadowFlag);
			damageTime = 5;
		}
		damageTime--;
		if (damageTime <= 0)
		{
			damageTime = 0;
			renderflag = false;
		}
	}
	else if (renderflag == false)
	{
		GameObject::Render(viwe, proj, ShadowFlag);
	}

}