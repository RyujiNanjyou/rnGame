#pragma once
#include "Sprite.h"
class GameOver2D
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	GameOver2D();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~GameOver2D();
	/*!
	* @brief	�������B
	*/
	void Init();
	/*!
	* @brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*/
	void Render();
private:
	Sprite over2D;
};

