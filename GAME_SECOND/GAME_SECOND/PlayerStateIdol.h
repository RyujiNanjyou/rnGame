#pragma once
#include "PlayerState.h"
/*!
*@brief	プレイヤーの待機状態。
*/
class PlayerStateIdol : public PlayerState
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerStateIdol(Player* player);
	/*!
	* @brief	デストラクタ。
	*/
	~PlayerStateIdol();
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
	* @brief	ロックオンできるかフラグ。
	*/
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

