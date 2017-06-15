#pragma once
#include "PlayerState.h"
/*!
*@brief	プレイヤーのダメージ状態。
*/
class PlayerStateDamage :
	public PlayerState
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerStateDamage(Player* player);
	/*!
	* @brief	デストラクタ。
	*/
	~PlayerStateDamage();
	/*!
	* @brief	更新。
	*/
	void Update() override;
	/*!
	* @brief	入る。
	*/
	void Enter() override;
	/*!
	* @brief	出る。
	*/
	void Leave() override;
	/*!
	* @brief	ダメージ可能かフラグ。
	*/
	bool IsPossibleDamage() const override
	{
		return false;
	}
	/*!
	* @brief	ロックオンできるかフラグ。
	*/
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

