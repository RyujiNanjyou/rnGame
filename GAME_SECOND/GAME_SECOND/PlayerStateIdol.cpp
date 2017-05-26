#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "GameScene.h"
#include "PlayerStateIdol.h"


PlayerStateIdol::PlayerStateIdol(Player* player):
PlayerState(player)
{
}


PlayerStateIdol::~PlayerStateIdol()
{
}

void PlayerStateIdol::Update()
{
	if (fabsf(game->GETPad()->GetLStickXF()) > 0.0001f || fabsf(game->GETPad()->GetLStickYF()) > 0.0001f)
	{
		player->ChangeState(player->STATE_RUN);
	}
	
	bool isOnGround = player->characterController.IsOnGround();
	D3DXVECTOR3 forward = player->forward;
	D3DXVECTOR3 pos = player->position;
	D3DXVECTOR3 moveSpeed = player->characterController.GetMoveSpeed();
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	if (player->characterController.IsCeiling()==true)
	{
		
	}
	if (game->GETPad()->IsPress(enButtonA) && !player->characterController.IsJump())
	{

		SoundSource* se = new SoundSource;
		se->Init("Assets/Sound/jump06.wav");
		se->Play(false);
		se->SetVolume(0.1f);
		moveSpeed.y = 6.5f;
		player->characterController.Jump();



	}
	if (game->GETPad()->IsPress(enButtonRB1))
	{
		player->ShotPlayer(pos, forward);
	}
	player->characterController.SetMoveSpeed(moveSpeed);
	player->characterController.Execute();
}
void PlayerStateIdol::Enter()
{
}
void PlayerStateIdol::Leave()
{

}