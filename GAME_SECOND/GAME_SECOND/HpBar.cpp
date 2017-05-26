#include "stdafx.h"
#include "GameScene.h"
#include "HpBar.h"


namespace
{
	const D3DXVECTOR2 maxsize = D3DXVECTOR2(390.0f , 30.0f);
	const D3DXVECTOR2 gaugesize = D3DXVECTOR2(413.0f , 50.0f);
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
	hpBar.Setpos(D3DXVECTOR3(280.0f, 405.0f, 0.0f));
	hpGauge.Setpos(D3DXVECTOR3(280.0f, 405.0f, 0.0f));
	

	
	
}
void HpBar::Update()
{
	float hpRate = (float)game->GetPlayer()->Gethp() / (float)game->GetPlayer()->Getmaxhp();
	D3DXVECTOR2 hpsize = maxsize ;
	// 一瞬前のHPバーのサイズを保存しておく。
	float hozonnHp_X = hpsize.x;
	hpsize.x *= hpRate;

	// 一瞬前のスケールを保存。
	float PrevScaleSize_X = hpBar.Getsize().x ;
	hpBar.Setsize(hpsize);
	if (game->GetPlayer()->Getpos().y < -10.0f)
	{
		
	}
	// 減った分、横にずらすための差分を算出。
	float offset = (PrevScaleSize_X - hpBar.Getsize().x ) / 2.0f;
	// ずらす。
	D3DXVECTOR3 pos = hpBar.Getpos();
	pos.x += offset;
	hpBar.Setpos(pos);
}
void HpBar::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	hpGauge.Render(viewMatrix, projMatrix);
	if ( game->GetPlayer()->GetNowS() != game->GetPlayer()->STATE_DEAD)
	{
		hpBar.Render(viewMatrix, projMatrix);
	}
	
}