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
class Sprite
{
public:
	Sprite();
	~Sprite();
	void Init(const char* TexPath) ;
	void Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
	void Setpos(D3DXVECTOR3 pos) { position = pos; }
	void Setsize(D3DXVECTOR2 s){ size = s; }
	void SetPivot(const D3DXVECTOR2& pivot){ this->pivot = pivot; }
	D3DXVECTOR3 Getpos(){ return position; }
	D3DXVECTOR2 Getsize(){ return size;}
	float Getalpha()const { return alpha; }
	void Setalpha(float a) { alpha = a; }
private:
	Primitive			primitive;			//!<プリミティブ。
	LPDIRECT3DTEXTURE9  texture = nullptr;			//!<テクスチャ。
	ID3DXEffect*		spriteEffect = nullptr;		//!<シェーダーエフェクト。
	D3DXVECTOR2			size = D3DXVECTOR2(1.0f, 1.0f);
	D3DXVECTOR2			pivot = D3DXVECTOR2(0.5f, 0.5f);
	D3DXVECTOR3			position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	float				alpha = 1.0f;
};

