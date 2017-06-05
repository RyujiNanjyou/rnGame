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
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag) override;
	void Damage();
	void Attackshot();
	int Gethp(){ return hp; }
	int Getmaxhp(){ return maxhp; }
	NowBossState GetBossS() { return nowbossS; }
	private:
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
private:
	NowBossState			nowbossS;
	float					radius = 0.3f;
	float					height = 0.7f;
	int						hp = 10;
	int						maxhp = 10;
	bool					comp = false;
	int	intervalTime = 0;
	int	intervalDamageTime = 0;
	float num = 0.0f;
	float deltaTime = 1.0f / 60.0f;
	int						damageTime = 0;
	bool					renderflag = false;
	std::unique_ptr<SoundSource> bossAttackse;
	std::unique_ptr<SoundSource> deathse;
};

