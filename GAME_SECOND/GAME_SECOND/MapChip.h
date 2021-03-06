	#pragma once

#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"


//マップチップの配置情報。


class MapChip : public GameObject
{
public:
	MapChip();
	~MapChip();
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	bool Update() override;
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass)override;
	
	
private:
	
	RigidBody rigidBody;		//剛体。
	MeshCollider meshCollider;	//メッシュコライダー。
	std::unique_ptr<D3DXMATRIX[]>		worldMatrixBuffer;	//ワールド行列のバッファ
};

