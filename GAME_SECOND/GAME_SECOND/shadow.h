#pragma once

#include "RenderTarget.h"
#include "SkinModel.h"
#include "SkinModelData.h"

/*!
*@brief	影。
*/
class ShadowMap
{
	D3DVIEWPORT9		viewport;			//ビューポート
	LPDIRECT3DSURFACE9	BackBuffer ;//バックバッファ
	LPDIRECT3DSURFACE9	BackZ;
	int					w, h;//横,縦
	RenderTarget		rendertarget;//レンダーターゲット
	D3DXVECTOR3			lightpos;//ライト座標
	D3DXVECTOR3			lightdir;//ライト向き
	D3DXMATRIX			rot;//回転
	D3DXMATRIX			world;//ワールド
	D3DXMATRIX			ProjMatrix;//プロジェクション
	D3DXMATRIX			LVPMatrix;//ライトビュープロジェクション
	D3DXMATRIX			lvMatrix;//ライトビュー
	ID3DXEffect*		pEffect;//エフェクト
	float				Near;				//近平面。
	float				Far;				//遠平面。
public:
	/*!
	* @brief	コンストラクタ
	*/
	ShadowMap();
	/*!
	* @brief	デストラクタ
	*/
	~ShadowMap();
	/*!
	* @brief	作成
	*@param[in] w　横
	*@param[in] h　縦
	*/
	void Create(int w, int h);
	/*!
	* @brief ライト作成
	*/
	void CreateLight(const D3DXMATRIX&);
	/*!
	* @brief	描画
	*@param[in]　viewMatrix　ビュー行列
	*@param[in]　projMatrix　プロジェクション行列
	*/
	void Render(
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix
		);
	/*!
	* @brief	開放
	*/
	void Release();
	/*!
	* @brief	レンダーターゲットの取得
	*/
	RenderTarget* GetRenderTarget() {
		return &rendertarget;
	}
	/*!
	* @brief	ライトビュープロジェクションの取得
	*/
	D3DXMATRIX Getlvpmatrix()const 
	{
		return LVPMatrix;
	}
	/*!
	* @brief	ライトの座標の設定
	*/
	void SetLightPosition(D3DXVECTOR3 pos)
	{
		lightpos = pos;
	}
	/*!
	* @brief	ライトの向きの設定
	*/
	void SetLightDirection(D3DXVECTOR3 Dir)
	{
		lightdir = Dir;
	}
	/*!
	* @brief	近平面の取得
	*/
	float GetNear() const
	{
		return Near;
	}
	/*!
	* @brief	遠平面の取得
	*/
	float GetFar() const
	{
		return Far;
	}
};
extern LPDIRECT3DTEXTURE9 shadow;
