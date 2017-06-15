#pragma once
#include "Primitive.h"
#include "SceneManager.h"
#include "Texture.h"
/*!
*@brief	座標とUV座標
*/
struct SShapeVertex {
	float		pos[4];
	float		uv[2];
};
static const D3DVERTEXELEMENT9 scShapeVertex_PT_Element[] = {
	{ 0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	D3DDECL_END()
};
/*!
*@brief 2D。
*/
class Sprite
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Sprite();
	/*!
	* @brief	デストラクタ。
	*/
	~Sprite();
	/*!
	*@brief	初期化。
	*@param[in] TexPath	テクスチャーパス
	*/
	void Init(const char* TexPath) ;
	/*!
	*@brief	更新。
	*/
	void Update();
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*/
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
	/*!
	* @brief	座標の設定
	*/
	void Setpos(D3DXVECTOR2& pos) { position = pos; }
	/*!
	* @brief	サイズの設定
	*/
	void Setsize(D3DXVECTOR2& s){ size = s; }
	/*!
	* @brief	ピボットの設定
	*/
	void SetPivot(const D3DXVECTOR2& pivot){ this->pivot = pivot; }
	/*!
	* @brief	座標の取得
	*/
	const D3DXVECTOR2& Getpos()const { return position; }
	/*!
	* @brief	サイズの取得
	*/
	const D3DXVECTOR2& Getsize()const { return size;}
	/*!
	* @brief	αの取得
	*/
	float Getalpha()const { return alpha; }
	/*!
	* @brief	αの設定
	*/
	void Setalpha(float a) { alpha = a; }
private:
	Primitive			primitive;			//プリミティブ。
	LPDIRECT3DTEXTURE9  texture = nullptr;			//テクスチャ。
	ID3DXEffect*		spriteEffect = nullptr;		//シェーダーエフェクト。
	D3DXVECTOR2			size = D3DXVECTOR2(1.0f, 1.0f);//サイズ
	D3DXVECTOR2			pivot = D3DXVECTOR2(0.5f, 0.5f);//ピボット
	D3DXVECTOR2			position = D3DXVECTOR2(0.0f, 0.0f);//座標
	D3DXQUATERNION		rotation;//回転。
	
	float				alpha = 1.0f;//α
};

