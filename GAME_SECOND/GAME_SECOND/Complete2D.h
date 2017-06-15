#pragma once
#include "Sprite.h"
/*!
* @brief	クリア2D。
*/
class Complete2D
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Complete2D();
	/*!
	* @brief	デストラクタ。
	*/
	~Complete2D();
	/*!
	* @brief	初期化。
	*/
	void Init();
	/*!
	*@brief	更新。
	*/
	void Update();
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*/
	void Render();
private:
	Sprite comp2D;
};

