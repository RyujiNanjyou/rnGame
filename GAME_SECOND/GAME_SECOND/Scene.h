#pragma once
#include "stdafx.h"
#include "shadow.h"
#include "Physics.h"
#include "Light.h"
#include "ParticleEmitter.h"

class Scene
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Scene(){}
	/*!
	* @brief	デストラクタ。
	*/
	virtual ~Scene()
	{
	}
	/*!
	* @brief	初期化。
	*/
	virtual void Init() = 0;
	/*!
	* @brief	更新。
	*/
	virtual void Update() = 0;
	/*!
	* @brief	描画。
	*/
	virtual void Render() = 0;
	
	/*!
	* @brief	パッドの取得。
	*/
	Pad* GETPad(){ return &pad; }
	/*!
	* @brief	ライトの取得。
	*/
	Light* GETlight(){ return &light;}
	/*!
	* @brief	影の取得。
	*/
	ShadowMap* Getshadow(){ return &shadow; }
	/*!
	* @brief	物理ワールドの取得。
	*/
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physics;
	}
	
protected:
	Pad					pad;//ゲームパッド
	ShadowMap			shadow;//影
	CParticleEmitter	particleEmitter;	//パーティクルエミッター
	Light				light;//ライト
	PhysicsWorld		physics;//物理ワールド
};
