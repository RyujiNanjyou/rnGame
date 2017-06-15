#pragma once
#include "Sprite.h"
class Enemy;
/*!
* @brief	���b�N�I��2D�B
*/
class LockOn2D
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	LockOn2D();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~LockOn2D();
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

	void SetLockOnEnemy(Enemy* enemy)
	{
		lockOnEnemy = enemy;
	}
private:
	Enemy* lockOnEnemy = NULL;
	Sprite lockOn2D;
};

