#pragma once
#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"

class EnemyManager;
/*!
*@brief	エネミー。
*/
class Enemy :public GameObject
{
public:
	enum EnemyS{IDOL = 0,DEATH,DAMAGE};
	/*!
	*@brief	コンストラクタ。
	*/
	Enemy();
	/*!
	*@brief	デストラクタ。
	*/
	~Enemy();
	/*!
	*@brief	初期化。
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	初期化。
	*/
	void Start(D3DXVECTOR3 pos, D3DXQUATERNION rotation);
	/*!
	*@brief	更新。
	*/
	bool Update() override;
	/*!
	*@brief	ダメージ。
	*/
	void Damage();
	/*!
	*@brief	描画。
	*/
	void  Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	ロックオンできるか。
	*/
	bool IsPossibleLockOn() 
	{
		return lock;
	}
	/*!
	*@brief	状態の設定。
	*/
	void SetnowEnemyS(EnemyS s) { nowEnemyS = s; }
	/*!
	*@brief	状態の取得。
	*/
	EnemyS GetnowEnemyS()const { return nowEnemyS; }
	/*!
	*@brief	死亡フラグの取得。
	*/
	bool GetDeathflag()const { return deathflag; }
	float GetHeight()const  { return height; }
private:
	EnemyS nowEnemyS;
	int hp = 2;
	bool deathflag = true;
	bool damageEffect = false;
	bool lock = true;
	int damageTime = 0;
	int intervalTime = 0;
	float radius = 0.3f;
	float height = 0.7f;
	std::unique_ptr<SoundSource> enemyJumpse;
	std::unique_ptr<SoundSource> enemyAttackse;
	std::unique_ptr<SoundSource> bombse;

};

