#pragma once
#include "RenderTarget.h"
/*!
*@brief	�u���[���B
*/
class Bloom
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Bloom();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Bloom();
	void Render();
	//	�d�݂̍X�V
	void UpdateWeight(float dispersion);
private:
	LPD3DXEFFECT effect;
	//�P�x�𒊏o���邽�߂̃����_�����O�^�[�Q�b�g��ǉ��B
	RenderTarget luminanceRenderTarget;
	RenderTarget downSamplingRenderTarget[2];	//!<�u���[�������邽�߂̃_�E���T���v�����O�p�̃����_�����O�^�[�Q�b�g�B
	static const int NUM_WEIGHTS = 8;			//!<�K�E�X�u���[�̏d�݁B
	float weights[NUM_WEIGHTS];					//!<�K�E�X�u���[�Ŏg���d�݃e�[�u���B
};

