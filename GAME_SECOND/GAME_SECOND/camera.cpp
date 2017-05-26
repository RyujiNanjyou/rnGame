#include "stdafx.h"
#include "camera.h"
//�R���X�g���N�^�B
Camera::Camera()
{
	Near = 0.1f;
	Far = 1000.0f;
	aspect = 1.0f;
}
//�f�X�g���N�^
Camera::~Camera()
{

}

//�J�����̍X�V�����B
void Camera::Update()
{
	D3DXMatrixLookAtLH(&viewMatrix, &vEyePt, &vLookatPt, &vUpVec);
	D3DXMatrixPerspectiveFovLH(&projectionMatrix, D3DX_PI / 4, aspect, Near, Far);
}
//�J�����̏������B
void Camera::Init()
{
	vEyePt = D3DXVECTOR3(0.0f, 0.5f, 2.0f);
	vLookatPt = D3DXVECTOR3(0.0f, 0.5f, 0.0f);
	vUpVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	Update();
}
