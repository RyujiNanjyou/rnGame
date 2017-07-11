#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "CharacterController.h"
#include "GameScene.h"
#include "PlayerStateDead.h"
namespace
{
	int num = 0;
}

PlayerStateDead::PlayerStateDead(Player* player) :
PlayerState(player)
{
	
}


PlayerStateDead::~PlayerStateDead()
{
}
void PlayerStateDead::Update()
{
	if (player->isApplyDeadTrigger)
	{
		scenemanager->ChangeScene(scenemanager->Scenes::GAME);
			
	}
}
void PlayerStateDead::Enter()
{
	
}
void PlayerStateDead::Leave()
{
	
}