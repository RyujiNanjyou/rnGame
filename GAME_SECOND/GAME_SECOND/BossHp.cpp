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
	// 一瞬前のHPバーのサイズを保存しておく。
	float hozonnHp_X = hpsize.x;
	hpsize.x *= hpRate;
	// 一瞬前のスケールを保存。
	float PrevScaleSize_X = bossHp.Getsize().x;
	bossHp.Setsize(hpsize);
	// 減った分、横にずらすための差分を算出。
	float offset = (PrevScaleSize_X - bossHp.Getsize().x) / 2.0f;
	// ずらす。
	D3DXVECTOR3 pos = bossHp.Getpos();
	pos.x += offset;
	bossHp.Setpos(pos);
}
void BossHp::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	bossHp.Render(viewMatrix, projMatrix);
}