#pragma once
#include "SkinModelData.h"
#include "CharacterController.h"
#include "Animation.h"
/*!
* @brief	ゲームオブジェクト
*/
class GameObject
{
public:
	/*!
	* @brief	コンストラクタ
	*/
	GameObject();
	/*!
	* @brief	デストラクタ
	*/
	~GameObject();
	/*!
	*@brief	初期化。
	*@param[in] pd3dDevice	デバイス
	*@param[in] Name		ファイル名
	*/
	virtual void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name);
	/*!
	*@brief	複数のオブジェクト用の初期化。
	*@param[in] pd3dDevice	デバイス
	*@param[in] modelData	モデルデータ
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, SkinModelData* modelData);
	/*!
	*@brief	更新。
	*/
	virtual bool Update();
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*@param[in] ShadowFlag	影を落とすかのフラグ
	*/
	virtual void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass);
	/*!
	*@brief	開放。
	*/
	virtual void Release();
	/*!
	*@brief	回転の設定。
	*/
	void Setrot(const D3DXQUATERNION& rot)
	{
		rotation = rot;
	}
	/*!
	*@brief	拡大の設定。
	*/
	void Setscale(const D3DXVECTOR3& scale)
	{
		this->scale = scale;
	}
	/*!
	*@brief	座標の設定。
	*/
	void Setpos(const D3DXVECTOR3& pos)
	{
		position = pos;
	}
	/*!
	*@brief	座標の取得。
	*/
	const D3DXVECTOR3& Getpos() const { return position; }
	/*!
	*@brief	回転の取得。
	*/
	const D3DXQUATERNION& Getrot()const { return rotation; }
	/*!
	*@brief	拡大の取得。
	*/
	const D3DXVECTOR3& Getscale()const { return scale; }
protected: 
	CharacterController     characterController;	//キャラクタコントローラ。
	ID3DXEffect*			effect;					//エフェクト。
	SkinModel				skinmodel;				//スキンモデル
	SkinModelData			skinmodeldata;			//スキンモデルデータ。
	D3DXVECTOR3				position;				//座標。
	D3DXQUATERNION			rotation;				//回転。
	D3DXVECTOR3				scale;					//拡大。
	D3DXMATRIX				mRot;					//回転行列。
	D3DXMATRIX				mWorld;					//ワールド行列。
	D3DXVECTOR3				moveDir;				//向き
	bool					Drawflag;				//描画フラグ。
	Animation				anim;					//アニメーション。
	D3DXVECTOR3				direction_z; 			//プレイヤーのZ方向。
	D3DXVECTOR3				direction_x; 			//プレイヤーのX方向。
};

