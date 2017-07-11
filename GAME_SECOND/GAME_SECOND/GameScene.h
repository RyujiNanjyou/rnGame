#pragma once
#include "Scene.h"
#include "PlayerCamera.h"
#include "bloom.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Tama.h"
#include "BossTama.h"
#include "EnemyTama.h"
#include "Boss.h"
#include "HpBar.h"
#include "Complete2D.h"
#include "GameOver2D.h"
#include "SkyBox.h"
#include "LockOn2D.h"

class Camera;
/*!
*@brief	ゲーム画面。
*/
class GameScene : public Scene 
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	GameScene();
	/*!
	* @brief	デストラクタ。
	*/
	~GameScene();
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
	/*!
	* @brief	カメラを取得。
	*/
	const Camera& GetCamera() const
	{
		return playcam.GetCamera();
	}
	/*!
	* @brief	ゲームカメラを取得。
	*/
	const PlayerCamera& GetGameCamera() const
	{
		return playcam;
	}
	/*!
	* @brief	プレイヤーを取得。
	*/
	Player* GetPlayer(){ return &player; }
	/*!
	* @brief	ボスの取得
	*/
	Boss* GetBoss() { return &boss; }
	/*!
	* @brief	エネミー管理クラスの取得
	*/
	EnemyManager* GetEnemyManager() { return &enemy; }
	/*!
	* @brief	プレイヤー弾の追加
	*/
	void AddPlayerTama(Tama* tama)
	{
		playertama.push_back(tama);
	}
	/*!
	* @brief	ボス弾の追加
	*/
	void AddBossTama(BossTama* tama)
	{
		bosstama.push_back(tama);
	}
	/*!
	* @brief	エネミー弾の追加
	*/
	void AddEnemyTama(EnemyTama* tama)
	{
		enemytama.push_back(tama);
	}
	/*!
	* @brief	プレイヤーが放った弾のリストを取得。
	*/
	const std::vector<Tama*>& GetPlayerTama() const
	{
		return playertama;
	}
	/*!
	* @brief	ボスが放った弾のリストを取得
	*/
	const std::vector<BossTama*>& GetBossTama() const
	{
		return bosstama;
	}
	/*!
	* @brief	エネミーが放った弾のリストを取得
	*/
	const std::vector<EnemyTama*>& GetEnemyTama() const
	{
		return enemytama;
	}
	LockOn2D* GetlockOn()  { return &lock2D; }
private:
	Bloom					bloom;//ブルーム
	Map						map;//マップ
	EnemyManager			enemy;//エネミーマネージャー
	PlayerCamera			playcam;//ゲームカメラ
	Player					player;//プレイヤー
	std::vector<Tama*>		playertama;//プレイヤー弾リスト
	std::vector<BossTama*>  bosstama;//ボス弾リスト
	std::vector<EnemyTama*> enemytama;//エネミー弾リスト
	Boss					boss;//ボス
	HpBar					hpB;//ヒットポイントバー2D
	Camera					camera2D;//2Dカメラ
	Complete2D				comp;//コンプリートの2D
	GameOver2D				over;//ゲームオーバーの2D
	LockOn2D				lock2D;
	SkyBox					sky;//背景
	SoundSource				bgm;//ステージサウンド
	SoundSource				bossbgm;//ボス戦サウンド
	
};
extern GameScene* game;
