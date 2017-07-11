#pragma once
#include "GameObject.h"
#include "Sprite.h"
/*!
*@brief	ボス。
*/
class Boss : public GameObject
{
public:
	//状態
	enum NowBossState
	{
		BossSTATE_RUN,//走る
		BossSTATE_IDOL,//待機
		BossSTATE_DAMAGE,//ダメージ
		BossSTATE_DEAD,//死亡
		BossSTATE_ATTACK//攻撃
	};
	/*!
	*@brief	コンストラクタ。
	*/
	Boss();
	/*!
	*@brief	デストラクタ。
	*/
	~Boss();
	/*!
	*@brief	初期化。
	*@param[in] pd3dDevice	デバイス
	*@param[in] Name		ファイル名
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	更新。
	*/
	bool Update() override;
	/*!
	*@brief	描画。
	*@param[in] viwe		ビュー行列
	*@param[in] proj		プロジェクション行列
	*@param[in] ShadowFlag	影を落とすかのフラグ
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	ダメージ処理。
	*/
	void Damage();
	/*!
	*@brief	攻撃。
	*/
	void Attackshot();
	/*!
	*@brief	ヒットポイント取得。
	*/
	int Gethp() const { return hp; }
	/*!
	*@brief	最大ヒットポイント取得。
	*/
	int Getmaxhp()const{ return maxhp; }
	/*!
	*@brief	ボスの状態の取得。
	*/
	NowBossState GetBossS() { return nowbossS; }
private:
	NowBossState					nowbossS;					//状態
	float							radius = 0.3f;				//横幅
	float							height = 0.7f;				//縦幅
	int								hp = 10;					//ヒットポイント
	const int						maxhp = 10;					//最大ヒットポイント
	bool							comp = false;				//クリアフラグ
	int								intervalTime = 0;			//クールタイム
	int								intervalDamageTime = 0;		//ダメージクールタイム
	int								renderTime = 0;				//描画クールタイム
	float							num = 0.0f;					//タイマー
	const float						deltaTime = 1.0f / 60.0f;	//デルタタイム
	bool							renderflag = false;			//描画フラグ
	std::unique_ptr<SoundSource>	bossAttackse;				//攻撃サウンド
	std::unique_ptr<SoundSource>	deathse;					//死亡サウンド
};

