#include "stdafx.h"
#include "CharacterController.h"
#include "GameScene.h"
#include "Tama.h"
#include "Enemy.h"
#include "BallCollision.h"
#include "Player.h"


namespace
{
	float  deltaTime = 1.0f / 60.0f;
	const D3DXVECTOR3 originpos(0.0f, 2.0f, 0.0f);
	const D3DXVECTOR3 bosspos(111.175f, -1.54f, 0.00f);
	const D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);
}
Player::Player() :
idolstate(this),
runstate(this),
damagestate(this),
deadstate(this)
{
	//初期化。
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
	direction_x = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	direction_z = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	forward = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
}


Player::~Player()
{
	Release();

}

void Player::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{
	
	D3DXCreateTextureFromFileA(pd3dDevice,
		"Assets/utc_nomal.tga",
		&normalMap
		);
	D3DXCreateTextureFromFileA(pd3dDevice,
		"Assets/utc_spec.tga",
		&specularMap
		);
	GameObject::Init(pd3dDevice, Name);

	if (normalMap != NULL) {
		//法線マップの読み込みが成功したので、SkinModelに法線マップを設定する。
		skinmodel.SetNormalMap(normalMap);
		skinmodel.SetNormalMapflag(true);

	}
	if (specularMap != NULL) {
		//スペキュラマップの読み込みが成功したので、SkinModelにスペキュラマップを設定する。
		skinmodel.SetSpecularMap(specularMap);
		skinmodel.SetSpecularMapflag(true);

	}
	PlayAnimation(INVALID, 0.0f);
	ChangeState(STATE_IDOL);
	anim.SetAnimationEndTime(RUN, 0.8f);
	anim.SetAnimationLoopFlag(JUMP, false);
	anim.PlayAnimation(IDOL);
	position = D3DXVECTOR3(bosspos);//bosspos,originpos
	rotation = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 pos = position;
	characterController.Init(radius, height, pos);
	characterController.SetGravity(-15.0f);	//重力強め。
	
	
}
void Player::PlayAnimation(PlayerAnimNo animNo, float interpolate)
{
	if (anim.GetPlayAnimNo() != animNo && animNo != INVALID) {
		//別のアニメーション
		anim.PlayAnimation(animNo, interpolate);
	}
}
void Player::Animation()
{
	if (characterController.IsJump())
	{
		PlayAnimation(JUMP, 0.05f);
	}
	else{
		if (state == STATE_RUN)
		{
			if (D3DXVec3LengthSq(&characterController.GetMoveSpeed()) > 16.0f)
			{
				PlayAnimation(RUN, 0.1f);
			}
		}
		else if (state == STATE_IDOL)
		{

			PlayAnimation(IDOL, 0.3f);
		}
		else if (state == STATE_DAMAGE)
		{
			if (isApplyDamageTrigger)
			{
				PlayAnimation(IDOL, 0.3f);
			}
		}
	}
	anim.Update(deltaTime);
}
bool Player::LockOnEnemy()
{
	bool f = false;
	D3DXMATRIX playerworld = skinmodel.Getworld();
	D3DXMatrixInverse(&playerworld, NULL, &playerworld);
	const std::vector<Enemy*>& enemylist = game->GetEnemyManager()->GetEnemy();
	float lockOnLen = 5.0f;
	Enemy* nearEnemy = NULL;
	float nearLen = FLT_MAX;
	for (auto enemy : enemylist)
	{
		if (!enemy->IsPossibleLockOn())
		{
			continue;
		}
		D3DXVECTOR3 pos = position - enemy->Getpos() ;
		
		float posLen = D3DXVec3Length(&pos);
		if (lockOnLen > posLen)
		{
			if (nearEnemy == NULL)
			{
				nearEnemy = enemy;
				nearLen = posLen;
			}
			else
			{
				if (posLen < nearLen)
				{
					nearEnemy = enemy;
					nearLen = posLen;
				}
			}
			f = true;
		}
	}
	lockOnEnemy = nearEnemy;
	return f;

}
void Player::UpdateState()
{

	if (currentState != NULL)
	{
		currentState->Update();
		if (currentState->IsPossibleLockOn())
		{
			if (!islockOn)
			{
				if (game->GETPad()->IsTrigger(enButtonLB3))
				{
					if (LockOnEnemy())
					{
						islockOn = true;
					}
				}
			}
			else
			{
				if (game->GETPad()->IsTrigger(enButtonLB3) || !lockOnEnemy->IsPossibleLockOn())
				{
					lockOnEnemy = NULL;
					islockOn = false;
				}
			}
			if (lockOnEnemy != NULL)
			{
				game->GetlockOn()->SetLockOnEnemy(lockOnEnemy);
			}
			
		}
		else
		{
			lockOnEnemy = NULL;
			islockOn = false;
		}
	}
	position = characterController.GetPosition();
}
void Player::Target()
{
	if (islockOn)
	{
		
		D3DXVECTOR3 toenemy = lockOnEnemy->Getpos() - position;
		D3DXQuaternionRotationAxis(&rotation, &Up, atan2f(toenemy.x, toenemy.z));
	}
	else
	{
		D3DXVECTOR3 movespeed = characterController.GetMoveSpeed();
		movespeed.y = 0.0f;
		if (D3DXVec3LengthSq(&movespeed) > 0.001f)
		{
			D3DXQuaternionRotationAxis(&rotation, &Up, atan2f(movespeed.x, movespeed.z));
		}
	}
}
void Player::ChangeState(NowState nexstate)
{
	if (currentState != NULL)
	{
		currentState->Leave();
	}
	switch (nexstate)
	{
	case STATE_IDOL:
		currentState = &idolstate;
		break;
	case STATE_RUN:
		currentState = &runstate;
		break;
	case STATE_DAMAGE:
		currentState = &damagestate;
		break;
	case STATE_DEAD:
		currentState = &deadstate;
		break;
	}
	state = nexstate;
	currentState->Enter();
}


void Player::ShotPlayer(D3DXVECTOR3 pos, D3DXVECTOR3 forward)
{
	
	if (shotintervalTime == 0)
	{
		Tama* tama = new Tama();
		pos.y += 0.5f;
		tama->Shot(pos, forward);
		tama->Init(g_pd3dDevice, "Assets/Model/tama");
		game->AddPlayerTama(tama);
		
		Attackse.reset(new SoundSource);
		Attackse->Init("Assets/Sound/beam-gun01.wav");
		Attackse->Play(false);
		Attackse->SetVolume(0.1f);
		shotintervalTime = 7;
	}
	shotintervalTime--;
	if (shotintervalTime <= 0)
	{
		shotintervalTime = 0;
	}
	
}

void Player::Damage()
{
	isApplyDamageTrigger = false;
	isDamage = false;
	if (currentState->IsPossibleDamage())
	{
		if (intervalTime == 0)
		{
			for (auto ene : game->GetEnemyManager()->GetEnemy())
			{

				if (BallCollision(position, ene->Getpos(), radius, 0.5f) && ene->GetDeathflag() == true)
				{
					hp -= 1;
					if (hp <= 0.0f)
					{
						isApplyDeadTrigger = true;
						hp = 0;
						ChangeState(STATE_DEAD);
					}
					else{
						isApplyDamageTrigger = true;

						renderflag = true;
						ChangeState(STATE_DAMAGE);
					}
				}
			}
			for (auto bosstama : game->GetBossTama())
			{
				if (BallCollision(position, bosstama->Getpos(), radius, 0.25f))
				{
					hp -= 2;
					if (hp <= 0.0f)
					{
						isApplyDeadTrigger = true;
						hp = 0;
						ChangeState(STATE_DEAD);
					}
					else{
						isApplyDamageTrigger = true;
						isDamage = true;
						renderflag = true;
						ChangeState(STATE_DAMAGE);
					}
				}
			}
			for (auto enemytama : game->GetEnemyTama())
			{
				if (BallCollision(position, enemytama->Getpos(), radius, 0.25f))
				{
					hp -= 1;
					if (hp <= 0.0f)
					{
						isApplyDeadTrigger = true;
						hp = 0;
						ChangeState(STATE_DEAD);
					}
					else{
						isApplyDamageTrigger = true;
						isDamage = true;
						renderflag = true;
						ChangeState(STATE_DAMAGE);
					}
				}
			}

			intervalTime = 5;
		}
		intervalTime--;
		if (intervalTime <= 0)
		{
			intervalTime = 0;
		}
	}
}
bool Player::Update()
{

	UpdateState();
	if (position.y < -10.0f)
	{
		isApplyDeadTrigger = true;
		hp = 0;
		ChangeState(STATE_DEAD);
	}
	Target();
	Damage();
	Animation();
	/*if (GetAsyncKeyState(VK_SPACE))
	{
		hp += 1;
	}*/
	GameObject::Update();
	lastFrameState = state;
	return true;
}
void Player::Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)
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