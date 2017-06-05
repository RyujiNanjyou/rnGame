#include "stdafx.h"
#include "GameScene.h"
#include "CharacterController.h"
#include "BallCollision.h"
#include "Tama.h"
#include "EnemyTama.h"
#include "Enemy.h"
namespace
{
	SkinModelData originalModelData;
	bool isLoadedOriginalModelData = false;
	
	
	
}

Enemy::Enemy()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	nowEnemyS = EnemyS::IDOL;
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

}


Enemy::~Enemy()
{
	Release();
}
void Enemy::Start(D3DXVECTOR3 pos, D3DXQUATERNION rotation)
{
	position = pos;
	this->rotation = rotation;
}
void Enemy::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	if (isLoadedOriginalModelData == false){
		//モデルのロードがまだ。
		char modelPath[256];
		sprintf(modelPath, "%s.X", Name);
		originalModelData.LoadModelData(modelPath, NULL);
		isLoadedOriginalModelData = true;
	}
	GameObject::Init(pd3dDevice, &originalModelData);
	nowEnemyS = EnemyS::IDOL;
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	float radius = 0.3f;
	float height = 0.7f;
	characterController.Init(radius, height,position);
	characterController.SetGravity(-20.0f);
	
}
void Enemy::Damage()
{
	for (auto tama : game->GetPlayerTama())
	{
		if (BallCollision(position, tama->Getpos(), 0.5f, 0.3f))
		{
			if (damageTime == 0)
			{
				hp--;
				damageTime = 5;
				nowEnemyS = EnemyS::DAMAGE;
			}
			damageTime--;
			if (damageTime <= 0)
			{
				damageTime = 0;
			}
		}

	}
	if (hp <= 0)
	{
		hp = 0;
		nowEnemyS = EnemyS::DEATH;
	}
	if (nowEnemyS == EnemyS::DEATH)
	{
		bombse.reset(new SoundSource);
		bombse->Init("Assets/Sound/bomb.wav");
		bombse->Play(false);
		bombse->SetVolume(0.8f);
		characterController.RemoveRigidBoby();
		deathflag = false;
		lock = false;
	}
}
bool Enemy::Update()
{
	lock = true;
	position = characterController.GetPosition();
	D3DXVECTOR3 move = characterController.GetMoveSpeed();
	move.x = 0.0f;
	move.z = 0.0f;
	D3DXVECTOR3 toPos = position - game->GetPlayer()->Getpos();
	float posLen = D3DXVec3Length(&toPos);
	if (posLen< 5.0f)
	{
		
		if (intervalTime == 0)
		{
			EnemyTama* tama = new EnemyTama();
			D3DXVECTOR3 pos = position;
			pos.y += 0.5;
			tama->Shot(pos, D3DXVECTOR3(-1.0f,0.0f,0.0f));
			tama->Init(g_pd3dDevice, "Assets/Model/tama");
			game->AddEnemyTama(tama);
			
			enemyAttackse.reset(new SoundSource);
			enemyAttackse->Init("Assets/Sound/beam-gun01.wav");
			enemyAttackse->Play(false);
			enemyAttackse->SetVolume(0.1f);
			intervalTime = 20;
		}
		intervalTime--;
		if (intervalTime <= 0)
		{
			intervalTime = 0;
		}
		if (!characterController.IsJump())
		{
			enemyJumpse.reset(new SoundSource);
			enemyJumpse->Init("Assets/Sound/jump01.wav");
			enemyJumpse->Play(false);
			enemyJumpse->SetVolume(0.1f);
			move.y += 10.0f;
			characterController.Jump();
		}
	}
	Damage();
	
	characterController.SetMoveSpeed(move);
	characterController.Execute();
	position.y += 0.4f;
	
	return true;
}
void Enemy::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
{
	GameObject::Update();
	GameObject::Render(viwe, proj, ShadowFlag);
}