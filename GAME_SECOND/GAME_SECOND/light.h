#pragma once 
#include "stdafx.h"

#define		LIGHT_NUM  4
/*!
*@brief	���C�g�B
*/
class Light
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Light()
	{
		//�f�B�t���[�Y�f�B���N�V�����B
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
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Light()
	{

	}
	/*!
	* @brief	�����̎擾�B
	*/
	const D3DXVECTOR4& GetDLDirecton() const { return *diffuseLightDirection; } 
	/*!
	* @brief	�J���[�̎擾�B
	*/
	const D3DXVECTOR4& GetDLColor() const { return *diffuseLightColor; }
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	const D3DXVECTOR4& Getamb() const { return ambientLight; }
	/*!
	* @brief	�����̐ݒ�B
	*/
	void Setamb(const D3DXVECTOR4 a){ ambientLight = a; }
	/*!
	* @brief	�f�B���N�V�����̐ݒ�B
	*/
	void SetDLDirecton(int n,D3DXVECTOR4 a) { diffuseLightDirection[n] = a; }
	/*!
	* @brief	�J���[�̐ݒ�B
	*/
	void SetDLColor(int n, D3DXVECTOR4 a) { diffuseLightColor[n] = a; }
	
private:

	D3DXVECTOR4 			diffuseLightDirection[LIGHT_NUM];	//���C�g�̕����B
	D3DXVECTOR4				diffuseLightColor[LIGHT_NUM];		//���C�g�̐F�B
	D3DXVECTOR4				ambientLight;						//����
};
