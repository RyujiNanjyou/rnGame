#include "stdafx.h"
#include "GameScene.h"
#include "HpBar.h"


namespace
{
	 D3DXVECTOR2 maxsize(390.0f , 30.0f);
	 D3DXVECTOR2 gaugesize(413.0f , 50.0f);
	 D3DXVECTOR2 BossposHp(0.0f, -300.0f);
	 D3DXVECTOR2 posHp(-400.0f, 300.0f);
	 D3DXVECTOR2 sizeHp(1000.0f, 50.0f);
}

HpBar::HpBar()
{
}

HpBar::~HpBar()
{
}
void HpBar::Init()
{
	hpBar.Init("Assets/Model/hp.png");
	hpGauge.Init("Assets/Model/hpsp_bar.png");
	hpBar.Setsize(maxsize);
	hpGauge.Setsize(gaugesize);
	hpBar.SetPivot({ 0.5f,0.5f });
	hpBar.Setpos(posHp);
	hpGauge.Setpos(posHp);
	bossHp.Init("Assets/Model/hp.png");
	bossHp.Setsize(sizeHp);
	bossHp.SetPivot({ 0.5f,0.5f });
	bossHp.Setpos(BossposHp);

	
	
}
void HpBar::Update()
{
	//後で関数化する

	//プレイヤーヒットポイント計算
	float hpRate = (float)game->GetPlayer()->Gethp() / (float)game->GetPlayer()->Getmaxhp();
	D3DXVECTOR2 hpsize = maxsize ;
	// 一瞬前のHPバーのサイズを保存しておく。
	float hozonnHp_X = hpsize.x;
	hpsize.x *= hpRate;

	// 一瞬前のスケールを保存。
	float PrevScaleSize_X = hpBar.Getsize().x ;
	hpBar.Setsize(hpsize);

	// 減った分、横にずらすための差分を算出。
	float offset = (PrevScaleSize_X - hpBar.Getsize().x ) / 2.0f;
	// ずらす。
	D3DXVECTOR2 pos = hpBar.Getpos();
	pos.x += offset;
	hpBar.Setpos(pos);

	//一応ボスのヒットポイント計算

	float hpRateB = (float)game->GetBoss()->Gethp() / (float)game->GetBoss()->Getmaxhp();
	D3DXVECTOR2 hpsizeB = sizeHp;
	// 一瞬前のHPバーのサイズを保存しておく。
	float BhozonnHp_X = hpsizeB.x;
	hpsizeB.x *= hpRateB;
	// 一瞬前のスケールを保存。
	float BPrevScaleSize_X = bossHp.Getsize().x;
	bossHp.Setsize(hpsizeB);
	// 減った分、横にずらすための差分を算出。
	float offsetB = (BPrevScaleSize_X - bossHp.Getsize().x) / 2.0f;
	// ずらす。
	D3DXVECTOR2 posB = bossHp.Getpos();
	posB.x += offsetB;
	bossHp.Setpos(posB);
}
void HpBar::Render()
{
	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	hpGauge.Render(identity, identity);
	if (game->GetPlayer()->GetNowS() != game->GetPlayer()->STATE_DEAD)
	{
		hpBar.Render(identity, identity);
	}
	D3DXVECTOR3 to = game->GetPlayer()->Getpos() - game->GetBoss()->Getpos();
	if (D3DXVec3Length(&to) < 5.0f)
	{
		bossHp.Render(identity, identity);
	}
	
}