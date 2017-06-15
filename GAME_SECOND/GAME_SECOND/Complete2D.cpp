#include "stdafx.h"
#include "GameScene.h"
#include "Complete2D.h"


Complete2D::Complete2D()
{
}


Complete2D::~Complete2D()
{
}
void Complete2D::Init()
{
	
	comp2D.Init("Assets/Model/comp.png");
	comp2D.SetPivot({ 0.5f, 0.5f });
	comp2D.Setpos(D3DXVECTOR2(0.0f, 0.0f));
	comp2D.Setsize(D3DXVECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT));
}

void Complete2D::Update()
{

}

void Complete2D::Render()
{
	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	if (game->GetBoss()->GetBossS() == game->GetBoss()->BossSTATE_DEAD)
	{
		comp2D.Render(identity, identity);
	}

}