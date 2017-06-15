#pragma once

class Player;

class PlayerState
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerState(Player* player)
	{
		this->player = player;
	}
	/*!
	* @brief	デストラクタ。
	*/
	virtual ~PlayerState()
	{
	}
	/*!
	* @brief	更新。
	*/
	virtual void Update() = 0;
	/*!
	* @brief	入る。
	*/
	virtual void Enter() = 0;
	/*!
	* @brief	出る。
	*/
	virtual void Leave() = 0;
	/*!
	* @brief	ダメージ可能かフラグ。
	*/
	virtual bool IsPossibleDamage() const
	{
		return true;
	}
	/*!
	* @brief	ロックオンできるかフラグ。
	*/
	virtual bool IsPossibleLockOn() const
	{
		return false;
	}
protected:
	Player* player;//プレイヤー
};

