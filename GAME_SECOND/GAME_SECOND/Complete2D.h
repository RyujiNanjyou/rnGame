#pragma once
#include "Sprite.h"
class Complete2D
{
public:
	Complete2D();
	~Complete2D();
	void Init();
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	Sprite comp2D;
};

