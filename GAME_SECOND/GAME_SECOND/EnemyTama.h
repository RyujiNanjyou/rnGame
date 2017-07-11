#pragma once
#include "BaseTama.h"
/*!
*@brief	エネミーの弾。
*/
class EnemyTama : public BaseTama
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	EnemyTama();
	/*!
	*@brief	デストラクタ。
	*/
	~EnemyTama();
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
	void Render(D3DXMATRIX viwe, D3DXMATRIX proj, bool ShadowFlag, bool isZPrepass);
};

