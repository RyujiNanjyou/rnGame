#pragma once
#include "GameObject.h"
#include "CharacterController.h"
#include "PlayerStateIdol.h"
#include "PlayerStateRun.h"
#include "PlayerStateDamage.h"
#include "PlayerStateDead.h"
#include "LockOn2D.h"
#include "Enemy.h"
/*!
* @brief	プレイヤー。
*/
class Player : public GameObject
{
public:
	//アニメーション状態。
	enum  PlayerAnimNo
	{
		INVALID = -1,
		IDOL = 0, //待機
		WALK, //歩く
		RUN, // 走る
		JUMP, //ジャンプ
	};
	//プレイヤーの状態。
	enum NowState
	{
		STATE_RUN, //走っている。
		STATE_IDOL, //待機している。
		STATE_DAMAGE, //ダメージ受けている。
		STATE_DEAD //死亡。
	};
	/*!
	*@brief	コンストラクタ。
	*/
	Player();
	/*!
	*@brief	デストラクタ
	*/
	~Player();
	/*!
	*@brief	初期化
	*@param[in] pd3dDevice	デバイス
	*@param[in] Name		ファイル名
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	更新
	*/
	bool Update() override;
	/*!
	*@brief	描画
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*@param[in] ShadowFlag	影を落とすかのフラグ
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	状態の更新
	*/
	void UpdateState();
	/*!
	* @brief	アニメーション再生。
	*/
	void PlayAnimation(PlayerAnimNo animNo, float interpolate);
	/*!
	*@brief	アニメーション。
	*/
	void Animation();
	/*!
	*@brief	状態遷移。
	*@param[in] nexstate	遷移させたい状態
	*/
	void ChangeState(NowState nexstate);
	/*!
	*@brief	ダメージ処理。
	*/
	void Damage();
	/*!
	*@brief	敵へのロックオン。
	*/
	bool LockOnEnemy();
	/*!
	*@brief	ターゲット。
	*/
	void Target();
	/*!
	*@brief	弾の撃つ処理。
	*/
	void ShotPlayer( D3DXVECTOR3& pos, const D3DXVECTOR3& forward);
	/*!
	*@brief	向きの取得。
	*/
	const D3DXVECTOR3&	Getforward() const { return forward; }
	/*!
	*@brief	ヒットポイントの取得。
	*/
	int Gethp()const{ return hp; }
	/*!
	*@brief	最大ヒットポイントの取得。
	*/
	const int Getmaxhp()const{ return maxhp; }
	/*!
	*@brief	ダメージフラグの取得。
	*/
	bool GetisDamage()const { return isDamage; }
	/*!
	*@brief	今の状態の取得。
	*/
	NowState GetNowS()const { return state; }

private:
	friend class	PlayerStateRun;
	friend class	PlayerStateIdol;
	friend class	PlayerStateDamage;
	friend class	PlayerStateDead;
	
	NowState						state;											//状態
	NowState						lastFrameState;									//最後のフレーム状態
	PlayerState*					currentState = NULL;							//現在状態
	PlayerStateIdol					idolstate;										//待機状態
	PlayerStateRun					runstate;										//走る状態
	PlayerStateDamage				damagestate;									//ダメージ状態
	PlayerStateDead					deadstate;										//死亡状態
	D3DXVECTOR3						forward;										//向き
	int								hp = 50;										//ヒットポイント
	const int						maxhp = 50;										//最大ヒットポイント
	float							radius = 0.4f;									//横幅
	float							height = 0.7f;									//縦幅
	bool							isApplyDamageTrigger = false;					//ダメージ適用フラグ
	bool							isApplyDeadTrigger = false;						//死亡適用フラグ
	bool							islockOn = false;								//ロックオンフラグ
	bool							isDamage =  false;								//ダメージフラグ
	Enemy*							lockOnEnemy = NULL;								//ロックオンできる敵
	LPDIRECT3DTEXTURE9				normalMap = skinmodel.GetNormal();				//<!ノーマルマップ。
	LPDIRECT3DTEXTURE9				specularMap = skinmodel.GetSpec();				//<!スペキュラマップ。
	LPDIRECT3DTEXTURE9				darkTex;
	int								intervalTime = 0;								//クールタイム
	int								shotintervalTime = 0;							//攻撃クールタイム
	int								damageTime = 0;									//ダメージクールタイム
	bool							renderflag = false;								//描画フラグ
	std::unique_ptr<SoundSource>	Attackse;										//攻撃サウンド
	std::unique_ptr<SoundSource>	Jumpse;											//ジャンプサウンド
	
};

