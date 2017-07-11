#pragma once

#include "RenderTarget.h"
#include "SkinModel.h"
#include "SkinModelData.h"

/*!
*@brief	�e�B
*/
class ShadowMap
{
	D3DVIEWPORT9		viewport;			//�r���[�|�[�g
	LPDIRECT3DSURFACE9	BackBuffer ;//�o�b�N�o�b�t�@
	LPDIRECT3DSURFACE9	BackZ;
	int					w, h;//��,�c
	RenderTarget		rendertarget;//�����_�[�^�[�Q�b�g
	D3DXVECTOR3			lightpos;//���C�g���W
	D3DXVECTOR3			lightdir;//���C�g����
	D3DXMATRIX			rot;//��]
	D3DXMATRIX			world;//���[���h
	D3DXMATRIX			ProjMatrix;//�v���W�F�N�V����
	D3DXMATRIX			LVPMatrix;//���C�g�r���[�v���W�F�N�V����
	D3DXMATRIX			lvMatrix;//���C�g�r���[
	ID3DXEffect*		pEffect;//�G�t�F�N�g
	float				Near;				//�ߕ��ʁB
	float				Far;				//�����ʁB
public:
	/*!
	* @brief	�R���X�g���N�^
	*/
	ShadowMap();
	/*!
	* @brief	�f�X�g���N�^
	*/
	~ShadowMap();
	/*!
	* @brief	�쐬
	*@param[in] w�@��
	*@param[in] h�@�c
	*/
	void Create(int w, int h);
	/*!
	* @brief ���C�g�쐬
	*/
	void CreateLight(const D3DXMATRIX&);
	/*!
	* @brief	�`��
	*@param[in]�@viewMatrix�@�r���[�s��
	*@param[in]�@projMatrix�@�v���W�F�N�V�����s��
	*/
	void Render(
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix
		);
	/*!
	* @brief	�J��
	*/
	void Release();
	/*!
	* @brief	�����_�[�^�[�Q�b�g�̎擾
	*/
	RenderTarget* GetRenderTarget() {
		return &rendertarget;
	}
	/*!
	* @brief	���C�g�r���[�v���W�F�N�V�����̎擾
	*/
	D3DXMATRIX Getlvpmatrix()const 
	{
		return LVPMatrix;
	}
	/*!
	* @brief	���C�g�̍��W�̐ݒ�
	*/
	void SetLightPosition(D3DXVECTOR3 pos)
	{
		lightpos = pos;
	}
	/*!
	* @brief	���C�g�̌����̐ݒ�
	*/
	void SetLightDirection(D3DXVECTOR3 Dir)
	{
		lightdir = Dir;
	}
	/*!
	* @brief	�ߕ��ʂ̎擾
	*/
	float GetNear() const
	{
		return Near;
	}
	/*!
	* @brief	�����ʂ̎擾
	*/
	float GetFar() const
	{
		return Far;
	}
};
extern LPDIRECT3DTEXTURE9 shadow;
