#pragma once
#include "RenderTarget.h"
/*!
*@brief	ブルーム。
*/
class Bloom
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	Bloom();
	/*!
	*@brief	デストラクタ。
	*/
	~Bloom();
	void Render();
	//	重みの更新
	void UpdateWeight(float dispersion);
private:
	LPD3DXEFFECT effect;
	//輝度を抽出するためのレンダリングターゲットを追加。
	RenderTarget luminanceRenderTarget;
	RenderTarget downSamplingRenderTarget[2];	//!<ブラーをかけるためのダウンサンプリング用のレンダリングターゲット。
	static const int NUM_WEIGHTS = 8;			//!<ガウスブラーの重み。
	float weights[NUM_WEIGHTS];					//!<ガウスブラーで使う重みテーブル。
};

