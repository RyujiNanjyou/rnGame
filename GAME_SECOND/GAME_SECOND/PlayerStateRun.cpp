#include "stdafx.h"
#include "Player.h"
#include "PlayerState.h"
#include "GameScene.h"
#include "PlayerStateRun.h"


PlayerStateRun::PlayerStateRun(Player* player) :
PlayerState(player)
{
}


PlayerStateRun::~PlayerStateRun()
{
}
void PlayerStateRun::Update()
{
	bool isOnGround = player->characterController.IsOnGround();
	D3DXVECTOR3 moveSpeed = player->characterController.GetMoveSpeed();
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	D3DXVECTOR3 movedir = player->moveDir;
	
	float move = 0.08f*60.0f;
	D3DXVECTOR3	padmovedir;
	padmovedir.x = game->GETPad()->GetLStickXF();
	padmovedir.y = 0.0f;
	padmovedir.z = game->GETPad()->GetLStickYF();
	movedir.x = player->direction_x.x * padmovedir.x - player->direction_z.x * padmovedir.z;
	movedir.z = player->direction_x.z * padmovedir.x - player->direction_z.z * padmovedir.z;
	//カメラが向いている方向に進む。
	player->direction_z = game->GetGameCamera().GetCameraDir();
	D3DXVec3Normalize(&movedir, &movedir);
	//カメラの向いている方向と、上ベクトルとの外積を計算すると横移動のベクトルが求まる。
	D3DXVec3Cross(&player->direction_x, &player->direction_z, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	//キャラクタが動く速度を設定。
	moveSpeed += movedir*move;
	//回転を計算。
	if (D3DXVec3Length(&movedir) > 0.0f)
	{
		player->forward.x = player->skinmodel.Getworld().m[2][0];
		player->forward.y = player->skinmodel.Getworld().m[2][1];
		player->forward.z = player->skinmodel.Getworld().m[2][2];
		D3DXVec3Normalize(&player->forward, &player->forward);
		float angle = acos(D3DXVec3Dot(&player->forward, &movedir));
		D3DXVECTOR3 axis;
		D3DXVec3Cross(&axis, &player->forward, &movedir);
		
		D3DXQuaternionRotationAxis(&player->rotation, &axis, angle);
	}
	if (D3DXVec3LengthSq(&movedir) < 0.0001f) {
		//立ち状態に遷移。
		player->ChangeState(player->STATE_IDOL);
	}
	if (game->GETPad()->IsPress(enButtonA) && !player->characterController.IsJump())
	{
		player->Jumpse.reset(new SoundSource);
		player->Jumpse->Init("Assets/Sound/jump06.wav");
		player->Jumpse->Play(false);
		player->Jumpse->SetVolume(0.1f);

		moveSpeed.y = 6.5f;
		player->characterController.Jump();
	}
	else {
		
	}
	if (game->GETPad()->IsPress(enButtonRB1))
	{
		player->ShotPlayer(player->position, player->forward);
	}
	
	player->characterController.SetMoveSpeed(moveSpeed);
	player->characterController.Execute();
}
void PlayerStateRun::Enter()
{
}
void PlayerStateRun::Leave()
{

}
