#pragma once
#include "GameObject.h"
/*!
* @brief	弾の基底クラス
*/
class BaseTama : public GameObject
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	BaseTama();
	/*!
	*@brief	デストラクタ。
	*/
	~BaseTama();
	/*!
	*@brief	初期化。
	*@param[in] pd3dDevice	デバイス
	*@param[in] Name		ファイル名
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	弾撃つ。
	*@param[in] pos			撃つ場所
	*@param[in] direction　	撃つ向き
	*/
	void Shot(const D3DXVECTOR3& pos, const D3DXVECTOR3& direction);
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*@param[in] ShadowFlag	影を落とすかのフラグ
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
protected:
	D3DXVECTOR3 dir;//向き
	int life;//寿命
	float radius = 0.1f;//横幅
	float height = 0.1f;//縦幅
};

