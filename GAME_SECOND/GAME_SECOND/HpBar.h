#pragma once
#include "Sprite.h"
/*!
*@brief	�q�b�g�|�C���g�B
*/
class HpBar
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	HpBar();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~HpBar();
	/*!
	*@brief	�������B
	*/
	void Init();
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�`��B
	*/
	void Render();
private:
	
	Sprite hpGauge;
	Sprite hpBar;
	Sprite bossHp;//�{�X�̃q�b�g�|�C���g��2D
};

