#pragma once
#include "Sprite.h"
#include "Texture.h"
/*!
*@brief	�^�C�g���B
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
	Sprite title;//�^�C�g���QD
};

