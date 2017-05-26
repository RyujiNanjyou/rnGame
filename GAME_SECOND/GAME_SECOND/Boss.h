#pragma once
#include "GameObject.h"
#include "Sprite.h"
class Boss : public GameObject
{
public:
	enum NowBossState
	{
		BossSTATE_RUN,
		BossSTATE_IDOL,
		BossSTATE_DAMAGE,
		BossSTATE_DEAD,
		BossSTATE_ATTACK
	};
	Boss();
	~Boss();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	bool Update() override;
	void Damage();
	int Gethp(){ return hp; }
	int Getmaxhp(){ return maxhp; }
	NowBossState GetBossS() { return nowbossS; }
private:
	NowBossState			nowbossS;
	float					radius = 0.3f;
	float					height = 0.7f;
	int						hp = 10;
	int						maxhp = 10;
	bool					comp = false;
	int	intervalTime = 0;
	int	intervalDamageTime = 0;
	int num = 0;
};

