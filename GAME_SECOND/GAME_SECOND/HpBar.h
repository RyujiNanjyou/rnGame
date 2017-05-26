#pragma once
#include "Sprite.h"

class HpBar
{
public:
	HpBar();
	~HpBar();
	void Init();
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	
	Sprite hpGauge;
	Sprite hpBar;
};

