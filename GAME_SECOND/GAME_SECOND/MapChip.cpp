#include "stdafx.h"
#include "GameScene.h"
#include "MapChip.h"
namespace
{

	SkinModelData originalModelData;
	bool isLoadedOriginalModelData = false;

}

MapChip::MapChip()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRot);
}


MapChip::~MapChip()
{
	game->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
}

void MapChip::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name)
{

	if (isLoadedOriginalModelData == false){
		//���f���̃��[�h���܂��B
		char modelPath[256];
		sprintf(modelPath, "%s.X", Name);
		originalModelData.LoadModelData(modelPath, NULL);
		isLoadedOriginalModelData = true;
	}
	GameObject::Init(pd3dDevice, &originalModelData);

	skinmodel.SetShadowReceiverFlag(true);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	//��������Փ˔��藍�݂̏������B
	GameObject::Update();
	//�X�L�����f�����烁�b�V���R���C�_�[���쐬����B
	D3DXMATRIX* rootBoneMatrix = originalModelData.GetRootBoneWorldMatrix();

	meshCollider.CreateFromSkinModel(&skinmodel, rootBoneMatrix);
	//�܂��͍��̂��쐬���邽�߂̏���ݒ�B
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;	//���̂̃R���W������ݒ肷��B
	rbInfo.mass = 0.0f;				    //���ʂ�0�ɂ���Ɠ����Ȃ����̂ɂȂ�B
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	rbInfo.scale = scale;
	//���̂��쐬�B
	rigidBody.Create(rbInfo);
	//�쐬�������̂𕨗����[���h�ɒǉ��B
	game->GetPhysicsWorld()->AddRigidBody(&rigidBody);


}
bool MapChip::Update()
{
	
	return true;
}
void MapChip::Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass)
{
	GameObject::Update();
	GameObject::Render(viwe, proj, ShadowFlag,isZPrepass);
}
