#pragma once
#include "GameObject.h"
#include "BaseTama.h"
class BossTama : public BaseTama
{
public:
	BossTama();
	~BossTama();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	bool Update();
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag) override;
};

