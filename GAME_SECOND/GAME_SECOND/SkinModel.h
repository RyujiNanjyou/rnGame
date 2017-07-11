/*!
*@brief	スキンモデル
*/
#pragma once

#include "Animation.h"

class SkinModelData;
class RenderContext;
class Light;

/*!
*@brief	スキンモデル
*/
class SkinModel
{
public:
	SkinModel();
	~SkinModel();
	/*!
	*@brief	初期化
	*/
	void Init(SkinModelData* modelData);
	/*!
	*@brief	描画。
	*/
	void Draw(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix, bool isDrawToShadowMap, bool isZPrepass);
	/*!
	*@brief	ワールド行列を更新。
	*@details
	* 後でCMotionクラスに移動させます。
	*@param[in]		trans	平行移動。
	*@param[in]		rot		回転。
	*@param[in]		scale	拡大。
	*/
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);

	void DrawMeshContainer(
		IDirect3DDevice9* pd3dDevice,
		LPD3DXMESHCONTAINER pMeshContainerBase,
		LPD3DXFRAME pFrameBase,
		ID3DXEffect* pEffect,
		const D3DXMATRIX&worldMatrix,
		const D3DXMATRIX& rotationMatrix,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX&projMatrix,
		Light* light,
		LPDIRECT3DTEXTURE9	normalMap,
		LPDIRECT3DTEXTURE9 specularMap,
		LPDIRECT3DTEXTURE9 darkTex,
		bool isDrawToShadowMap,
		bool isZPrepass
	);

	void DrawFrame(
		IDirect3DDevice9* pd3dDevice,
		LPD3DXFRAME pFrame,
		ID3DXEffect* pEffect,
		const D3DXMATRIX& worldMatrix,
		const D3DXMATRIX& rotationMatrix,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix,
		Light* light,
		LPDIRECT3DTEXTURE9	normalMap,
		LPDIRECT3DTEXTURE9 specularMap,
		LPDIRECT3DTEXTURE9 darkTex,
		bool isDrawToShadowMap,
		bool isZPrepass
	);
	/*!
	*@brief	ライトを設定。
	*/
	void SetLight(Light* light)
	{
		this->light = light;
	}
	void SetShadowReceiverFlag(bool flag)
	{
		ShadowReceiverFlag = flag;
	}
	void SetDrawToShadowMap(bool flag)
	{
		isDrawToShadowMap = flag;
	}
	/*!
	*@brief 法線マップフラグを設定。
	*/
	void SetNormalMapflag(bool flag)
	{
		isNormalMap = flag;
	}
	void SetSpecularMapflag(bool flag)
	{
		isSpecularMap = flag;
	}
	void SetDarkTextuerflag(bool flag)
	{
		isDarkTextuer = flag;
	}
	ID3DXEffect* GetEffect()
	{
		return pEffect;
	}
	void SetEffect(ID3DXEffect* effect)
	{
		pEffect = effect;
	}
	const D3DXMATRIX Getworld()const
	{
		return worldMatrix;
	}
	const D3DXMATRIX& GetRot() const
	{
		return rotationMatrix;
	}
	/*!
	* @brief	先頭のメッシュを取得。
	*/
	LPD3DXMESH GetOrgMeshFirst() const;
	/*!
	* @brief	ノーマルマップセット。
	*/
	void SetNormalMap(LPDIRECT3DTEXTURE9 normal)
	{
		normalMap = normal;
	}
	/*!
	*@brief スペキュラマップを設定。
	*/
	void SetSpecularMap(LPDIRECT3DTEXTURE9 specMap)
	{
		specularMap = specMap;
	}
	/*!
	* @brief	ダークテクスチャセット。
	*/
	void SetDarkTextuer(LPDIRECT3DTEXTURE9 specMap)
	{
		darkTex = specMap;
	}
	LPDIRECT3DTEXTURE9 GetNormal() const
	{
		return normalMap;
	}
	LPDIRECT3DTEXTURE9 GetSpec() const
	{
		return specularMap;
	}

	LPDIRECT3DTEXTURE9 GetDarkTextuer() const
	{
		return darkTex;
	}
private:
	D3DXMATRIX			worldMatrix;			//!<ワールド行列。
	D3DXMATRIX			rotationMatrix;			//!<回転行列。
	SkinModelData*		skinModelData;			//!<スキンモデルデータ。
	ID3DXEffect*		pEffect;				//!<エフェクト。
	Animation			animation;				//!<アニメーション。
	Light*				light;					//!<ライト。
	bool				ShadowReceiverFlag;
	bool				isDrawToShadowMap;
	bool				isNormalMap;			//<!ノーマルマップフラグ
	bool				isSpecularMap;		//<!スペキュラマップフラグ
	bool				isDarkTextuer;
	LPDIRECT3DTEXTURE9	normalMap = NULL;				//<!ノーマルマップ。
	LPDIRECT3DTEXTURE9  specularMap = NULL;				//<!スペキュラマップ。
	LPDIRECT3DTEXTURE9  darkTex = NULL;
};