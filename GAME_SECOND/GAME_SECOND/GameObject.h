#pragma once
#include "SkinModelData.h"
#include "CharacterController.h"
#include "Animation.h"

class GameObject
{
public:
	GameObject();
	~GameObject();
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, SkinModelData* modelData);
	virtual bool Update();
	virtual void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag);
	virtual void Release();

	void Setrot(D3DXQUATERNION rot)
	{
		rotation = rot;
	}
	void Setscale(D3DXVECTOR3 scale)
	{
		this->scale = scale;
	}

	void Setpos(D3DXVECTOR3 pos)
	{
		position = pos;
	}
	D3DXVECTOR3 Getpos() const { return position; }
	D3DXQUATERNION Getrot()const { return rotation; }
	D3DXVECTOR3 Getscale()const { return scale; }
protected: 
	CharacterController     characterController;	//�L�����N�^�R���g���[���B
	ID3DXEffect*			effect;					//�G�t�F�N�g�B
	SkinModel				skinmodel;
	SkinModelData			skinmodeldata;
	D3DXVECTOR3				position;				//���W�B
	D3DXQUATERNION			rotation;				//��]�B
	D3DXVECTOR3				scale;
	D3DXMATRIX				mRot;
	D3DXMATRIX				mWorld;					//���[���h�s��
	D3DXVECTOR3				moveDir;
	bool					Drawflag;
	Animation				anim;
	D3DXVECTOR3				direction_z; 			//�v���C���[��Z�����B
	D3DXVECTOR3				direction_x; 			//�v���C���[��X�����B
};

