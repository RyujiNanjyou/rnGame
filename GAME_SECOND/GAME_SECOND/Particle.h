/*!
* @brief	パーティクル。
*/
#ifndef _TKPARTICLE_H_
#define _TKPARTICLE_H_

#include "Primitive.h"

struct SParicleEmitParameter;
/*!
* @brief	パーティクル。
*/
class CParticle{
	Primitive			primitive;			//!<プリミティブ。
	LPDIRECT3DTEXTURE9	texture;			//!<テクスチャ。
	ID3DXEffect*		shaderEffect;		//!<シェーダーエフェクト。
	D3DXVECTOR3			moveSpeed;			//!<速度。
	D3DXVECTOR3			position;			//!<座標。
	float				life = 0.0f;
public:
	CParticle();
	~CParticle();
	void Init(const SParicleEmitParameter& param);
	bool Update();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
};

#endif //_TKPARTICLE_H_
