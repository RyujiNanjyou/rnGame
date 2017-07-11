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
		//モデルのロードがまだ。
		char modelPath[256];
		sprintf(modelPath, "%s.X", Name);
		originalModelData.LoadModelData(modelPath, NULL);
		isLoadedOriginalModelData = true;
	}
	GameObject::Init(pd3dDevice, &originalModelData);

	skinmodel.SetShadowReceiverFlag(true);
	scale = D3DXVECTOR3(1.0f, 1.0f, 1.0f);

	//ここから衝突判定絡みの初期化。
	GameObject::Update();
	//スキンモデルからメッシュコライダーを作成する。
	D3DXMATRIX* rootBoneMatrix = originalModelData.GetRootBoneWorldMatrix();

	meshCollider.CreateFromSkinModel(&skinmodel, rootBoneMatrix);
	//まずは剛体を作成するための情報を設定。
	RigidBodyInfo rbInfo;
	rbInfo.collider = &meshCollider;	//剛体のコリジョンを設定する。
	rbInfo.mass = 0.0f;				    //質量を0にすると動かない剛体になる。
	rbInfo.pos = position;
	rbInfo.rot = rotation;
	rbInfo.scale = scale;
	//剛体を作成。
	rigidBody.Create(rbInfo);
	//作成した剛体を物理ワールドに追加。
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
