#pragma once
#include "GameObject.h"
class BaseTama : public GameObject
{
public:
	BaseTama();
	~BaseTama();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag) override;
protected:
	D3DXVECTOR3 dir;
	int life;
	float radius = 0.1f;
	float height = 0.1f;
};

