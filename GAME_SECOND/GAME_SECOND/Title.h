#pragma once
#include "Sprite.h"
#include "Texture.h"
class Title 
{
public:
	Title();
	~Title();
	void Init() ;
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
private:
	Sprite title;

};

