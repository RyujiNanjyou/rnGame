#include "stdafx.h"
#include "GameScene.h"
#include "PlayerCamera.h"


PlayerCamera::PlayerCamera() :
toEyePos(0.0f, 0.0f, 0.0f, 1.0f),
targetOffset(0.0f, 0.0f, 0.0f, 1.0f),
cameraDir(0.0f, 0.0f, 0.0f)
{
}
PlayerCamera::~PlayerCamera()
{
}
void PlayerCamera::Start(Player* player)
{
	toEyePos.z = -8.0f;
	toEyePos.y = 2.0f;
	targetOffset.y = 1.0f;
	targetOffset.x = 0.0f;
	camera.SetAspect(1280.0f / 720.0f);
	camera.Init();
	this->player = player;
	UpdateCamera();
}
//カメラを更新。
void PlayerCamera::UpdateCamera()
{

	D3DXVECTOR3 target;
	//追従したものの指定
	target = player->Getpos();
	target.x += targetOffset.x;
	target.y += targetOffset.y;
	target.z += targetOffset.z;
	D3DXVECTOR3 eyePos = target;
	eyePos.x += toEyePos.x;
	eyePos.y += toEyePos.y;
	eyePos.z += toEyePos.z;

	camera.SetEyePt(eyePos);
	camera.SetLookatPt(target);
	camera.Update();
}
void PlayerCamera::PreUpdate()
{
	//ゲームパッド
	float padMove_X = game->GETPad()->GetRStickXF();
	float padMove_Y = game->GETPad()->GetRStickXF();
	//左右
	if (fabsf(padMove_X) > 0.0f)
	{
		//Y軸周りの回転を計算。
		//回す
		D3DXMATRIX mRot_X;
		D3DXMatrixRotationY(&mRot_X, 0.05f * padMove_X);
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot_X);
	}
	if (fabsf(padMove_X) < 1.0f)
	{
		//Y軸周りの回転を計算。
		//回す
		D3DXMATRIX mRot_Y;
		D3DXMatrixRotationY(&mRot_Y, -0.05f * padMove_Y);
		D3DXVec4Transform(&toEyePos, &toEyePos, &mRot_Y);
	}
	//上下
	/*if (fabsf(padMove_Y) > 0.0f)
	{
	D3DXVECTOR3 rotAxis;
	D3DXVec3Cross(&rotAxis, &camera.GetUpVec(), &(D3DXVECTOR3)toEyePos);
	D3DXVec3Normalize(&rotAxis, &rotAxis);
	D3DXMATRIX mRot;
	D3DXMatrixRotationAxis(&mRot, &rotAxis, 0.05f * padMove_Y);

	D3DXVECTOR3 toPositionOld = toEyePos;
	D3DXVec4Transform(&toEyePos, &toEyePos, &mRot);
	D3DXVECTOR3 toPosDir = toEyePos;
	D3DXVec3Normalize(&toPosDir, &toPosDir);
	if (toPosDir.y < -0.1f) {
	カメラが上向きすぎ。
	toEyePos = (D3DXVECTOR4)toPositionOld;
	}
	else if (toPosDir.y > 0.8f) {
	カメラが下向きすぎ。
	toEyePos = (D3DXVECTOR4)toPositionOld;
	}
	}
	*/
	cameraDir = D3DXVECTOR3(toEyePos);
	cameraDir.y = 0.0f;
	D3DXVec3Normalize(&cameraDir, &cameraDir);
}
void PlayerCamera::Update()
{
	UpdateCamera();
}