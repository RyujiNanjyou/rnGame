#pragma once
#include "SkinModelData.h"
#include "CharacterController.h"
#include "Animation.h"
/*!
* @brief	�Q�[���I�u�W�F�N�g
*/
class GameObject
{
public:
	/*!
	* @brief	�R���X�g���N�^
	*/
	GameObject();
	/*!
	* @brief	�f�X�g���N�^
	*/
	~GameObject();
	/*!
	*@brief	�������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	/*!
	*@brief	�����̃I�u�W�F�N�g�p�̏������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] modelData	���f���f�[�^
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, SkinModelData* modelData);
	/*!
	*@brief	�X�V�B
	*/
	virtual bool Update();
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*@param[in] ShadowFlag	�e�𗎂Ƃ����̃t���O
	*/
	virtual void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass);
	/*!
	*@brief	�J���B
	*/
	virtual void Release();
	/*!
	*@brief	��]�̐ݒ�B
	*/
	void Setrot(const D3DXQUATERNION& rot)
	{
		rotation = rot;
	}
	/*!
	*@brief	�g��̐ݒ�B
	*/
	void Setscale(const D3DXVECTOR3& scale)
	{
		this->scale = scale;
	}
	/*!
	*@brief	���W�̐ݒ�B
	*/
	void Setpos(const D3DXVECTOR3& pos)
	{
		position = pos;
	}
	/*!
	*@brief	���W�̎擾�B
	*/
	const D3DXVECTOR3& Getpos() const { return position; }
	/*!
	*@brief	��]�̎擾�B
	*/
	const D3DXQUATERNION& Getrot()const { return rotation; }
	/*!
	*@brief	�g��̎擾�B
	*/
	const D3DXVECTOR3& Getscale()const { return scale; }
protected: 
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
	ID3DXEffect*			effect;					//�G�t�F�N�g�B
	SkinModel				skinmodel;				//�X�L�����f��
	SkinModelData			skinmodeldata;			//�X�L�����f���f�[�^�B
	D3DXVECTOR3				position;				//���W�B
	D3DXQUATERNION			rotation;				//��]�B
	D3DXVECTOR3				scale;					//�g��B
	D3DXMATRIX				mRot;					//��]�s��B
	D3DXMATRIX				mWorld;					//���[���h�s��B
	D3DXVECTOR3				moveDir;				//����
	bool					Drawflag;				//�`��t���O�B
	Animation				anim;					//�A�j���[�V�����B
	D3DXVECTOR3				direction_z; 			//�v���C���[��Z�����B
	D3DXVECTOR3				direction_x; 			//�v���C���[��X�����B
};

