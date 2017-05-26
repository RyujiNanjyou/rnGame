#pragma once
#include "GameObject.h"
#include "CharacterController.h"
#include "PlayerStateIdol.h"
#include "PlayerStateRun.h"
#include "PlayerStateDamage.h"
#include "PlayerStateDead.h"
#include "Enemy.h"

class Player : public GameObject
{
public:
	
	enum  PlayerAnimNo
	{
		INVALID = -1,
		IDOL = 0,
		WALK,
		RUN,
		JUMP,
	};
	enum NowState
	{
		STATE_RUN,
		STATE_IDOL,
		STATE_DAMAGE,
		STATE_DEAD
	};
	Player();
	~Player();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	bool Update() override;
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)override;
	void UpdateState();
	void PlayAnimation(PlayerAnimNo animNo, float interpolate);
	void Animation();
	void ChangeState(NowState nexstate);
	void Damage();
	bool LockOnEnemy();
	D3DXQUATERNION SetRotation(const D3DXVECTOR3 axis, float angle)
	{
		float s;
		float halfAngle = angle * 0.5f;
		s = sin(halfAngle);
		rotation.w = cos(halfAngle);
		rotation.x = axis.x * s;
		rotation.y = axis.y * s;
		rotation.z = axis.z * s;

		return rotation;
	}
	void Target();
	void ShotPlayer(D3DXVECTOR3 pos, D3DXVECTOR3 forward);
	D3DXVECTOR3	Getforward() { return forward; }
	int Gethp(){ return hp; }
	int Getmaxhp(){ return maxhp; }
	bool GetisDamage() { return isDamage; }
	NowState GetNowS() { return state; }

private:
	friend class	PlayerStateRun;
	friend class	PlayerStateIdol;
	friend class	PlayerStateDamage;
	friend class	PlayerStateDead;
	
	NowState				state;
	NowState				lastFrameState;
	PlayerState*			currentState = NULL;
	PlayerStateIdol			idolstate;
	PlayerStateRun			runstate;
	PlayerStateDamage		damagestate;
	PlayerStateDead			deadstate;
	D3DXVECTOR3				forward;
	int						hp = 50;
	int						maxhp = 50;
	float					radius = 0.4f;
	float					height = 0.7f;
	bool					isApplyDamageTrigger = false;
	bool					isApplyDeadTrigger = false;
	bool					islockOn = false;
	bool					isDamage =  false;
	Enemy*					lockOnEnemy = NULL;
	LPDIRECT3DTEXTURE9		normalMap = skinmodel.GetNormal();				//<!ノーマルマップ。
	LPDIRECT3DTEXTURE9		specularMap = skinmodel.GetSpec();				//<!スペキュラマップ。

	int						intervalTime = 0; 
	int						shotintervalTime = 0;
	int						damageTime = 0;
	bool					renderflag = false;
	
};

