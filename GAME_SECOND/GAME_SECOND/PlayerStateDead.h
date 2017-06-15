#pragma once
#include "Sprite.h"
#include "PlayerState.h"
/*!
*@brief	�v���C���[�̎��S��ԁB
*/
class PlayerStateDead : public PlayerState
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerStateDead(Player* player);
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~PlayerStateDead();
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
};

