#pragma once
#include "PlayerState.h"
/*!
*@brief	プレイヤーのダッシュ状態。
*/
class PlayerStateRun : public PlayerState
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerStateRun(Player* player);
	/*!
	* @brief	デストラクタ。
	*/
	~PlayerStateRun();
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

