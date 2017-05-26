#pragma once
#include "Sprite.h"
class BossHp
{
public:
	BossHp();
	~BossHp();
	void Init();
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	Sprite bossHp;
};

