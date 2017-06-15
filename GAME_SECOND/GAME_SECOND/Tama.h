#pragma once
#include "GameObject.h"
#include "BaseTama.h"
class Enemy;
/*!
*@brief	プレイヤーの弾。
*/
class Tama : public BaseTama
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Tama();
	/*!
	*@brief	デストラクタ。
	*/
	~Tama();
	/*!
	*@brief	初期化。
	*@param[in] pd3dDevice	デバイス
	*@param[in] Name		ファイル名
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	/*!
	*@brief	更新。
	*/
	bool Update();
	/*!
	*@brief	弾撃つ。
	*@param[in] pos			撃つ場所
	*@param[in] direction　	撃つ向き
	*/
	void Shot(D3DXVECTOR3& pos, D3DXVECTOR3& direction);
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*@param[in] ShadowFlag	影を落とすかのフラグ
	*/
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag);
};

