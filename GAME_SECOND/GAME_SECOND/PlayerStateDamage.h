#pragma once
#include "PlayerState.h"
/*!
*@brief	�v���C���[�̃_���[�W��ԁB
*/
class PlayerStateDamage :
	public PlayerState
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerStateDamage(Player* player);
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~PlayerStateDamage();
	/*!
	* @brief	�X�V�B
	*/
	void Update() override;
	/*!
	* @brief	����B
	*/
	void Enter() override;
	/*!
	* @brief	�o��B
	*/
	void Leave() override;
	/*!
	* @brief	�_���[�W�\���t���O�B
	*/
	bool IsPossibleDamage() const override
	{
		return false;
	}
	/*!
	* @brief	���b�N�I���ł��邩�t���O�B
	*/
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

