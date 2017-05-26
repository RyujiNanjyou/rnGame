#pragma once

class Player;

class PlayerState
{
public:
	PlayerState(Player* player)
	{
		this->player = player;
	}
	virtual ~PlayerState()
	{
	}
	virtual void Update() = 0;
	virtual void Enter() = 0;
	virtual void Leave() = 0;
	virtual bool IsPossibleDamage() const
	{
		return true;
	}
	virtual bool IsPossibleLockOn() const
	{
		return false;
	}
protected:
	Player* player;
};

