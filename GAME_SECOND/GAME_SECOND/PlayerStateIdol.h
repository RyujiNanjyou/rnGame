#pragma once
#include "PlayerState.h"
/*!
*@brief	�v���C���[�̑ҋ@��ԁB
*/
class PlayerStateIdol : public PlayerState
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerStateIdol(Player* player);
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~PlayerStateIdol();
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
	* @brief	���b�N�I���ł��邩�t���O�B
	*/
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

