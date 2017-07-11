#pragma once
#include "BaseTama.h"
/*!
*@brief	�G�l�~�[�̒e�B
*/
class EnemyTama : public BaseTama
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	EnemyTama();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~EnemyTama();
	/*!
	*@brief	�������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	/*!
	*@brief	�X�V�B
	*/
	bool Update();
	/*!
	*@brief	�e���B
	*@param[in] pos			���ꏊ
	*@param[in] direction�@	������
	*/
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*@param[in] ShadowFlag	�e�𗎂Ƃ����̃t���O
	*/
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag, bool isZPrepass);
};

