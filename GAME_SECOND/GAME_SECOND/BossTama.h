#pragma once
#include "GameObject.h"
#include "BaseTama.h"
class BossTama : public BaseTama
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	BossTama();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~BossTama();
	/*!
	*@brief	�������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	�X�V�B
	*/
	bool Update();
	/*!
	*@brief	�e���B
	*@param[in] pos			���ꏊ
	*@param[in] direction�@	������
	*/
	void Shot(const D3DXVECTOR3& pos, const D3DXVECTOR3& direction);
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*@param[in] ShadowFlag	�e�𗎂Ƃ����̃t���O
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
};

