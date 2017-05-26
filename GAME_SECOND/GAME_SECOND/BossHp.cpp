#include "stdafx.h"
#include "GameScene.h"
#include "BossHp.h"

namespace
{
	const D3DXVECTOR3 posHp(0.0f, -50.0f, 0.0f);
	const D3DXVECTOR2 sizeHp(1000.0f, 30.0f);
}

BossHp::BossHp()
{
}


BossHp::~BossHp()
{
}

void BossHp::Init()
{
	
	bossHp.Init("Assets/Model/hp.png");
	bossHp.Setsize(sizeHp);
	bossHp.SetPivot({ 0.5f,0.5f });
	bossHp.Setpos(posHp);
	
}
void BossHp::Update()
{
	float hpRate = (float)game->GetBoss()->Gethp() / (float)game->GetBoss()->Getmaxhp();
	D3DXVECTOR2 hpsize = sizeHp;
	// ��u�O��HP�o�[�̃T�C�Y��ۑ����Ă����B
	float hozonnHp_X = hpsize.x;
	hpsize.x *= hpRate;
	// ��u�O�̃X�P�[����ۑ��B
	float PrevScaleSize_X = bossHp.Getsize().x;
	bossHp.Setsize(hpsize);
	// ���������A���ɂ��炷���߂̍������Z�o�B
	float offset = (PrevScaleSize_X - bossHp.Getsize().x) / 2.0f;
	// ���炷�B
	D3DXVECTOR3 pos = bossHp.Getpos();
	pos.x += offset;
	bossHp.Setpos(pos);
}
void BossHp::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	bossHp.Render(viewMatrix, projMatrix);
}