#include "stdafx.h"
#include "GameScene.h"
#include "GameOver2D.h"


GameOver2D::GameOver2D()
{
}


GameOver2D::~GameOver2D()
{
}

void GameOver2D::Init()
{
	over2D.Init("Assets/Model/GameOver.png");
	over2D.SetPivot({ 0.5f, 0.5f });
	over2D.Setpos(D3DXVECTOR2(0.0f, 0.0f));
	over2D.Setsize(D3DXVECTOR2(1200,620));
}

void GameOver2D::Update()
{

}

void GameOver2D::Render()
{
	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	if (game->GetPlayer()->GetNowS() == game->GetPlayer()->STATE_DEAD)
	{
		over2D.Render(identity, identity);
	}
}