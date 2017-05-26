#pragma once 
#include "stdafx.h"

#define		LIGHT_NUM  4
class Light
{
	
	D3DXVECTOR4 			diffuseLightDirection[LIGHT_NUM];	//���C�g�̕����B
	D3DXVECTOR4				diffuseLightColor[LIGHT_NUM];		//���C�g�̐F�B
	D3DXVECTOR4				ambientLight;						//����
public:
	Light()
	{
		diffuseLightDirection[0] = D3DXVECTOR4(0.707f, -0.707f, 0.0f, 1.0f);
		diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
		diffuseLightDirection[2] = D3DXVECTOR4(-0.707f, -0.707f, 0.0f, 1.0f);
		diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

		//�f�B�t���[�Y���C�g�B
		diffuseLightColor[0] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[1] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[2] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

		//�����B
		ambientLight = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 0.5f);
	}
	~Light()
	{

	}
	
	const D3DXVECTOR4& GetDLDirecton() const { return *diffuseLightDirection; } 
	const D3DXVECTOR4& GetDLColor() const { return *diffuseLightColor; }
	const D3DXVECTOR4& Getamb() const { return ambientLight; }
	void Setamb(const D3DXVECTOR4 a){ ambientLight = a; }
	void SetDLDirecton(int n,D3DXVECTOR4 a) { diffuseLightDirection[n] = a; }
	void SetDLColor(int n, D3DXVECTOR4 a) { diffuseLightColor[n] = a; }
	
};
