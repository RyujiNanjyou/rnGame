#pragma once
#include "light.h"
#include "camera.h"
/*!
*@brief	背景。
*/
class SkyBox
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	SkyBox();
	/*!
	* @brief	デストラクタ。
	*/
	~SkyBox();
	/*!
	* @brief	初期化。
	*/
	void Init();
	/*!
	* @brief	更新。
	*/
	void Update();
	/*!
	* @brief	描画。
	*/
    void Render();
private:
	SkinModelData skinmodeldata;//スキンモデルデータ
	SkinModel skinmodel;//スキンモデル
	Light light;//ライト
	Camera camera;//カメラ
};

