#pragma once
#include "Sprite.h"
class GameOver2D
{
public:
	GameOver2D();
	~GameOver2D();
	void Init();
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	Sprite over2D;
};

