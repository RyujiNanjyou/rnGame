#pragma once
#include "Sprite.h"
#include "PlayerState.h"
class PlayerStateDead : public PlayerState
{
public:
	PlayerStateDead(Player* player);
	~PlayerStateDead();
	void Update() override;
	void Enter() override;
	void Leave() override;
	bool IsPossibleDamage() const override
	{
		return false;
	}
};

