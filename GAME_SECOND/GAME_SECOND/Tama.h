#pragma once
#include "GameObject.h"
#include "BaseTama.h"
class Enemy;
class Tama : public BaseTama
{
public:
	Tama();
	~Tama();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	bool Update();
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag);
};

