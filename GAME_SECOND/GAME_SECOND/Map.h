#pragma once
#include "MapChip.h"

/*!
* @brief	マップクラス。
*/
class Map{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Map();
	/*!
	* @brief	デストラクタ。
	*/
	~Map();
	/*!
	* @brief	初期化。
	*/
	void Start();
	/*!
	* @brief	更新。
	*/
	void Update();
	/*!
	* @brief	描画。
	*/
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix,
		const D3DXVECTOR4& diffuseLightDirection,
		const D3DXVECTOR4& diffuseLightColor,
		const D3DXVECTOR4& ambientLight,
		int lightnum
		);

private:
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;		//回転行列
	std::vector<MapChip*> mapChipList;	//マップチップのリスト。
};