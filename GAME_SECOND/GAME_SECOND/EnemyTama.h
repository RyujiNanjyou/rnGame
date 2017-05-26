#pragma once
#include "BaseTama.h"

class EnemyTama : public BaseTama
{
public:
	EnemyTama();
	~EnemyTama();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	bool Update();
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag);
};

