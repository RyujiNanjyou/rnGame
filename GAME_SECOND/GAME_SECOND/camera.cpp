#include "stdafx.h"
#include "camera.h"
//コンストラクタ。
Camera::Camera()
{
	Near = 0.1f;
	Far = 1000.0f;
	aspect = 1.0f;
}
//デストラクタ
Camera::~Camera()
{

}

//カメラの更新処理。
void Camera::Update()
{
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, D3DX_PI / 4, aspect, Near, Far);
	D3DXMatrixLookAtLH(&viewMatrix, &vEyePt, &vLookatPt, &vUpVec);
	D3DXMatrixMultiply(&viewproj, &viewMatrix, &projectionMatrix);

}
//カメラの初期化。
void Camera::Init()
{
	vEyePt = D3DXVECTOR3(0.0f, 0.5f, 2.0f);
	vLookatPt = D3DXVECTOR3(0.0f, 0.5f, 0.0f);
	vUpVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Update();
}
void Camera::CalcScreenPositionFromWorldPosition(D3DXVECTOR2& screenPos, const D3DXVECTOR3& worldPos) const
{
	float half_w = (float)WINDOW_WIDTH * 0.5f;
	float half_h = (float)WINDOW_HEIGHT * 0.5f;
	D3DXVECTOR4 _screenPos;
	_screenPos = D3DXVECTOR4(worldPos.x, worldPos.y, worldPos.z, 1.0f);
	D3DXVec4Transform(&_screenPos, &_screenPos, &viewproj);
/*	_screenPos.x = _screenPos.x * viewproj.m[0][0] + _screenPos.y * viewproj.m[1][0] + _screenPos.z * viewproj.m[2][0] + _screenPos.w * viewproj.m[3][0];
	_screenPos.y = _screenPos.x * viewproj.m[0][1] + _screenPos.y * viewproj.m[1][1] + _screenPos.z * viewproj.m[2][1] + _screenPos.w * viewproj.m[3][1];
	_screenPos.z = _screenPos.x * viewproj.m[0][2] + _screenPos.y * viewproj.m[1][2] + _screenPos.z * viewproj.m[2][2] + _screenPos.w * viewproj.m[3][2];
	_screenPos.w = _screenPos.x * viewproj.m[0][3] + _screenPos.y * viewproj.m[1][3] + _screenPos.z * viewproj.m[2][3] + _screenPos.w * viewproj.m[3][3];*/
	screenPos.x = (_screenPos.x / _screenPos.w)*half_w;
	screenPos.y = (_screenPos.y / _screenPos.w)*half_h;
}
