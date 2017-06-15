#pragma once
#include "Sprite.h"
class GameOver2D
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	GameOver2D();
	/*!
	*@brief	デストラクタ。
	*/
	~GameOver2D();
	/*!
	* @brief	初期化。
	*/
	void Init();
	/*!
	* @brief	更新。
	*/
	void Update();
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*/
	void Render();
private:
	Sprite over2D;
};

