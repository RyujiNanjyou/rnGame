#pragma once
#include "camera.h"

class Player;

//ゲームカメラ
class PlayerCamera
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	PlayerCamera();
	/*!
	* @brief	デストラクタ。
	*/
	~PlayerCamera();
	/*!
	*@brief	初期化。
	*@param[in] player　カメラに追尾してほしいオブジェクトを指定
	*/
	void Start(Player* player);
	/*!
	*@brief	更新の前の更新。
	*/
	void PreUpdate();
	/*!
	*@brief	更新。
	*/
	void Update();
	//カメラを取得。
	const Camera& GetCamera() const
	{
		return camera;
	}
	//カメラの方向を取得。
	D3DXVECTOR3 GetCameraDir() const
	{
		return cameraDir;
	}
private:
	//カメラを更新。
	void UpdateCamera();
Camera		camera;
	Player*		player;			//追従するプレイヤー。
	D3DXVECTOR4 targetOffset;	//注視点のオフセット。
	D3DXVECTOR4 toEyePos;		//注視点から視点までのベクトル。	
	D3DXVECTOR3 cameraDir;		//カメラの方向。
};


