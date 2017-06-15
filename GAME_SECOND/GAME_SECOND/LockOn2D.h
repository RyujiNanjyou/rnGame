#pragma once
#include "Sprite.h"
class Enemy;
/*!
* @brief	ロックオン2D。
*/
class LockOn2D
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	LockOn2D();
	/*!
	* @brief	デストラクタ。
	*/
	~LockOn2D();
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

	void SetLockOnEnemy(Enemy* enemy)
	{
		lockOnEnemy = enemy;
	}
private:
	Enemy* lockOnEnemy = NULL;
	Sprite lockOn2D;
};

