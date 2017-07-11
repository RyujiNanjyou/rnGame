#pragma once
#include "GameObject.h"
/*!
* @brief	�e�̊��N���X
*/
class BaseTama : public GameObject
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	BaseTama();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~BaseTama();
	/*!
	*@brief	�������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
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
protected:
	D3DXVECTOR3 dir;//����
	int life;//����
	float radius = 0.1f;//����
	float height = 0.1f;//�c��
};

