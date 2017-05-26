#pragma once
#include "PlayerState.h"
class PlayerStateDamage :
	public PlayerState
{
public:
	PlayerStateDamage(Player* player);
	~PlayerStateDamage();
	void Update() override;
	void Enter() override;
	void Leave() override;
	bool IsPossibleDamage() const override
	{
		return false;
	}
	bool IsPossibleLockOn() const override
	{
		return true;
	}
};

