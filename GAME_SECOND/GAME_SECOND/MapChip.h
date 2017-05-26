	#pragma once

#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"


//�}�b�v�`�b�v�̔z�u���B


class MapChip : public GameObject
{
public:
	MapChip();
	~MapChip();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	bool Update() override;
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag)override;
	
	
private:
	
	RigidBody rigidBody;		//���́B
	MeshCollider meshCollider;	//���b�V���R���C�_�[�B
	std::unique_ptr<D3DXMATRIX[]>		worldMatrixBuffer;	//���[���h�s��̃o�b�t�@
};

