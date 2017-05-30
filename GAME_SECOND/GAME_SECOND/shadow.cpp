#include "stdafx.h"
#include "GameScene.h"
#include "Enemy.h"
#include "shadow.h"


ShadowMap::ShadowMap()
{
	pEffect = NULL;
}
ShadowMap::~ShadowMap()
{
	Release();
}

void ShadowMap::Create(int w, int h)
{
	D3DXMatrixIdentity(&rot);


	rendertarget.Create(w, h, 1, D3DFMT_A8R8G8B8, D3DFMT_D16, D3DMULTISAMPLE_NONE, 0);
	this->h = h;
	this->w = w;
	Near = 0.1f;
	Far = 100.0f;
	LPD3DXBUFFER  compileErrorBuffer = NULL;
}


void ShadowMap::Render(
	D3DXMATRIX* viewMatrix,
	D3DXMATRIX* projMatrix
	)
{
	g_pd3dDevice->GetViewport(&viewport);
	g_pd3dDevice->GetRenderTarget(0, &BackBuffer);
	g_pd3dDevice->GetDepthStencilSurface(&BackZ);

	g_pd3dDevice->SetRenderTarget(0, rendertarget.GetRenderTarget());
	g_pd3dDevice->SetDepthStencilSurface(rendertarget.GetDepthStencilBuffer());

	g_pd3dDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DXCOLOR(1.0f,1.0f,1.0f, 1.0f),
		1.0f,
		0);

	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	D3DXMatrixOrthoLH(&ProjMatrix,20,20, Near, Far);
	CreateLight(ProjMatrix);
	game->GetPlayer()->Render(lvMatrix, ProjMatrix, true);
	for (auto enemy : game->GetEnemyManager()->GetEnemy())
	{
		if (enemy->GetDeathflag() == true)
		{
			enemy->Render(lvMatrix, ProjMatrix, true);
		}
	}
	game->GetBoss()->Render(lvMatrix, ProjMatrix, true);
	for (auto tama : game->GetPlayerTama())
	{
		
		tama->Render(lvMatrix, ProjMatrix, true);
		
	}
	for (auto tama : game->GetEnemyTama())
	{
		
		tama->Render(lvMatrix, ProjMatrix, true);
		
	}
	for (auto tama : game->GetBossTama())
	{
	
		tama->Render(lvMatrix, ProjMatrix, true);
		
	}

	g_pd3dDevice->SetRenderTarget(0, BackBuffer);
	g_pd3dDevice->SetDepthStencilSurface(BackZ);
	g_pd3dDevice->SetViewport(&viewport);
	g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	shadow = rendertarget.GetTexture();
}

void ShadowMap::CreateLight(D3DXMATRIX proj)
{
	D3DXVECTOR3 lightUp;
	float t = fabsf(D3DXVec3Dot(&lightdir, &D3DXVECTOR3(0.0f, 1.0f, 0.0f)));
	if (fabsf((t - 1.0f)) < 0.00001f)
	{
		lightUp = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	}
	else
	{
		lightUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	}
	D3DXVECTOR3 target;
	D3DXVec3Add(&target, &lightpos, &lightdir);
	D3DXMatrixLookAtLH(&lvMatrix, &lightpos, &target, &lightUp);
	D3DXMatrixMultiply(&LVPMatrix, &lvMatrix, &proj);
}
void ShadowMap::Release()
{
	if (pEffect != nullptr) {

		pEffect = nullptr;
	}
}