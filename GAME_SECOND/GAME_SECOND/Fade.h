#pragma once
#include "Sprite.h"
class Fade
{
public:
	Fade();
	~Fade();
	/*!
	*@brief	�J�n�֐��B
	*@details
	* �������Ȃǂ����̊֐��Ɏ������Ă��������B</br>
	* ���̊֐���true��Ԃ��Ɩ{�ِ��͈ȍ~�̃t���[���ł͌Ă΂�Ȃ��Ȃ�܂��B</br>
	* �����ăQ�[���I�u�W�F�N�g�̏�Ԃ������������ɂȂ�Update�֐����Ă΂��悤�ɂȂ�܂��B</br>
	*@return	true���A���Ă����珉���������B
	*/
	bool Start() ;
	/*!
	*@brief	�X�V�֐��B
	*/
	void Update() ;
	/*!
	*@brief	�x���`��֐��B
	@details
	* �|�X�g�G�t�F�N�g�̌�Ŏ��s����܂��BHUD�Ȃǃ|�X�g�G�t�F�N�g�̉e�����󂯂����Ȃ��`�敨�͂����Ń����_�����O���Ă��������B
	*@param[in]		renderContext		�����_�����O�R���e�L�X�g�B
	*/
	void PostRender(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix) ;
	/*!
	*@brief	�t�F�[�h�̏��������s���H�B
	*@return �t�F�[�h�C���A�t�F�[�h�A�E�g�����s����true��Ԃ��܂��B
	*/
	bool IsExecute() const
	{
		return isExecute;
	}
	/*!
	*@brief	�t�F�[�h�A�E�g���J�n�B
	*/
	void StartFadeOut()
	{
		float alpha = sprite.Getalpha();
		if (alpha < 1.0f) {
			timer = 0.0f;
			//SetActiveFlag(true);
			isExecute = true;
			state = eFadeOut;
		}
	}
	/*!
	*@brief	�t�F�[�h�C�����J�n�B
	*/
	void StartFadeIn()
	{
		float alpha = sprite.Getalpha();
		if (alpha > 0.0f) {
			timer = 0.0f;
			//SetActiveFlag(true);
			isExecute = true;
			state = eFadeIn;
		}
		
	}
private:
	//��ԁB
	enum EnState {
		eFadeOut,		//!<�t�F�[�h�A�E�g�B
		eFadeIn,		//!<�t�F�[�h�C���B
	};
	const float FADE_TIME = 0.3f;		//!<�t�F�[�h�A�E�g�̎��ԁB(�P�ʁF�b)
	Sprite		sprite;				//!�u���b�N�A�E�g�p�̃X�v���C�g�B
	EnState		state = eFadeIn;		//!<��ԁB
	bool		isExecute = false;	//!<�t�F�[�h�����s���H
	float		timer = 1.0f;			//!<�^�C�}(�P�ʁF�b)
};

