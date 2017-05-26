#include "stdafx.h"
#include "MapChip.h"
#include "Map.h"

using namespace std;
namespace {
	struct SMapChipLocInfo {
		const char* modelName;		//モデル。
		D3DXVECTOR3	pos;			//座標。
		D3DXQUATERNION	rotation;		//回転。
	};
	//マップチップの配置情報のテーブル。
	SMapChipLocInfo mapChipLocInfoTable[] =
	{
		#include "locationInfo.h"
	};
}
Map::Map()
{

}
Map::~Map()
{
	for (auto& mapchip : mapChipList){
		delete mapchip;
	}
}
void Map::Start()
{
	//配置情報からマップを構築
	int tableSize = sizeof(mapChipLocInfoTable) / sizeof(mapChipLocInfoTable[0]);

	for (int i = 0; i < tableSize; i++)
	{

		//マップチップを生成
		MapChip* mapChip = new MapChip;
		mapChip->Setpos(mapChipLocInfoTable[i].pos);
		mapChip->Setrot(mapChipLocInfoTable[i].rotation);
		mapChip->Init(g_pd3dDevice, mapChipLocInfoTable[i].modelName);
		mapChipList.push_back(mapChip);

	}
}
void Map::Update()
{
	
}
void Map::Render(
	LPDIRECT3DDEVICE9 pd3dDevice,
	D3DXMATRIX viewMatrix,
	D3DXMATRIX projMatrix,
	const D3DXVECTOR4 diffuseLightDirection,
	const D3DXVECTOR4 diffuseLightColor,
	D3DXVECTOR4	 ambientLight,
	int lightnum
	)
{
	for (auto& mapChip : mapChipList)
	{
		mapChip->Render(viewMatrix, projMatrix, false);
	}
}
