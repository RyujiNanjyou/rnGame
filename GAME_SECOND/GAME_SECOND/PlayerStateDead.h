#pragma once
#include "Sprite.h"
#include "PlayerState.h"
/*!
*@brief	プレイヤーの死亡状態。
*/
class PlayerStateDead : public PlayerState
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerStateDead(Player* player);
	/*!
	* @brief	デストラクタ。
	*/
	~PlayerStateDead();
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
};

