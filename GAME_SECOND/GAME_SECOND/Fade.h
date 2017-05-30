#pragma once
#include "Sprite.h"
class Fade
{
public:
	Fade();
	~Fade();
	/*!
	*@brief	開始関数。
	*@details
	* 初期化などをこの関数に実装してください。</br>
	* この関数がtrueを返すと本館数は以降のフレームでは呼ばれなくなります。</br>
	* そしてゲームオブジェクトの状態が初期化完了になりUpdate関数が呼ばれるようになります。</br>
	*@return	trueが帰ってきたら初期化完了。
	*/
	bool Start() ;
	/*!
	*@brief	更新関数。
	*/
	void Update() ;
	/*!
	*@brief	遅延描画関数。
	@details
	* ポストエフェクトの後で実行されます。HUDなどポストエフェクトの影響を受けたくない描画物はここでレンダリングしてください。
	*@param[in]		renderContext		レンダリングコンテキスト。
	*/
	void PostRender(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix) ;
	/*!
	*@brief	フェードの処理を実行中？。
	*@return フェードイン、フェードアウトを実行中はtrueを返します。
	*/
	bool IsExecute() const
	{
		return isExecute;
	}
	/*!
	*@brief	フェードアウトを開始。
	*/
	void StartFadeOut()
	{
		float alpha = sprite.Getalpha();
		if (alpha < 1.0f) {
			timer = 0.0f;
			//SetActiveFlag(true);
			isExecute = true;
			state = eFadeOut;
		}
	}
	/*!
	*@brief	フェードインを開始。
	*/
	void StartFadeIn()
	{
		float alpha = sprite.Getalpha();
		if (alpha > 0.0f) {
			timer = 0.0f;
			//SetActiveFlag(true);
			isExecute = true;
			state = eFadeIn;
		}
		
	}
private:
	//状態。
	enum EnState {
		eFadeOut,		//!<フェードアウト。
		eFadeIn,		//!<フェードイン。
	};
	const float FADE_TIME = 0.3f;		//!<フェードアウトの時間。(単位：秒)
	Sprite		sprite;				//!ブラックアウト用のスプライト。
	EnState		state = eFadeIn;		//!<状態。
	bool		isExecute = false;	//!<フェードを実行中？
	float		timer = 1.0f;			//!<タイマ(単位：秒)
};

