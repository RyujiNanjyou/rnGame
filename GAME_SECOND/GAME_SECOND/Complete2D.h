#pragma once
#include "Sprite.h"
/*!
* @brief	�N���A2D�B
*/
class Complete2D
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Complete2D();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Complete2D();
	/*!
	* @brief	�������B
	*/
	void Init();
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*/
	void Render();
private:
	Sprite comp2D;
};

