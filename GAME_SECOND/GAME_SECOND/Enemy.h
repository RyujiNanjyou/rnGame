#pragma once
#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"

class EnemyManager;
class Enemy :public GameObject
{
public:
	enum EnemyS{IDOL = 0,DEATH,DAMAGE};
	Enemy();
	~Enemy();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	void Start(D3DXVECTOR3 pos, D3DXQUATERNION rotation);
	bool Update() override;
	void Damage();
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)override;
	bool IsPossibleLockOn() 
	{
		return lock;
	}
	void SetnowEnemyS(EnemyS s) { nowEnemyS = s; }
	EnemyS GetnowEnemyS(){ return nowEnemyS; }
	bool GetDeathflag(){ return deathflag; }
	bool GetDamageEffectflag(){ return damageEffect; }
	void SetDamageEffectflag(bool f) { damageEffect = f; }
private:
	EnemyS nowEnemyS;
	int hp = 2;
	bool deathflag = true;
	bool damageEffect = false;
	bool lock = true;
	int damageTime = 0;
	int intervalTime = 0;
};

