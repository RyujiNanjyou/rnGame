#pragma once
#include "Sprite.h"
#include "Texture.h"
/*!
*@brief	タイトル。
*/
class Title 
{
public:
	Title();
	~Title();
	void Init() ;
	void Update();
	void Render();
private:
	Sprite title;//タイトル２D
};

