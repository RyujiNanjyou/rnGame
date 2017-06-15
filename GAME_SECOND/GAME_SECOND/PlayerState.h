#pragma once

class Player;

class PlayerState
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerState(Player* player)
	{
		this->player = player;
	}
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	virtual ~PlayerState()
	{
	}
	/*!
	* @brief	�X�V�B
	*/
	virtual void Update() = 0;
	/*!
	* @brief	����B
	*/
	virtual void Enter() = 0;
	/*!
	* @brief	�o��B
	*/
	virtual void Leave() = 0;
	/*!
	* @brief	�_���[�W�\���t���O�B
	*/
	virtual bool IsPossibleDamage() const
	{
		return true;
	}
	/*!
	* @brief	���b�N�I���ł��邩�t���O�B
	*/
	virtual bool IsPossibleLockOn() const
	{
		return false;
	}
protected:
	Player* player;//�v���C���[
};

