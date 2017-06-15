#pragma once
#include "Sprite.h"
/*!
*@brief	ヒットポイント。
*/
class HpBar
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	HpBar();
	/*!
	*@brief	デストラクタ。
	*/
	~HpBar();
	/*!
	*@brief	初期化。
	*/
	void Init();
	/*!
	*@brief	更新。
	*/
	void Update();
	/*!
	*@brief	描画。
	*/
	void Render();
private:
	
	Sprite hpGauge;
	Sprite hpBar;
	Sprite bossHp;//ボスのヒットポイントの2D
};

