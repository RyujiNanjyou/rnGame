#pragma once
#include "PlayerState.h"
/*!
*@brief	�v���C���[�̃_�b�V����ԁB
*/
class PlayerStateRun : public PlayerState
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerStateRun(Player* player);
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~PlayerStateRun();
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

