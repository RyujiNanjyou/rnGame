#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "CharacterController.h"
#include "PlayerStateDamage.h"


PlayerStateDamage::PlayerStateDamage(Player* player) :
PlayerState(player)
{
}


PlayerStateDamage::~PlayerStateDamage()
{
}
void PlayerStateDamage::Update()
{
	D3DXVECTOR3 moveSpeed = player->characterController.GetMoveSpeed();
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	if (player->isApplyDamageTrigger)
	{
		player->ChangeState(player->STATE_IDOL);
	}
	player->characterController.SetMoveSpeed(moveSpeed);
	player->characterController.Execute();
	
}
void PlayerStateDamage::Enter()
{
}
void PlayerStateDamage::Leave()
{

}