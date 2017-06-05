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
#include "BossHp.h"
#include "Complete2D.h"
#include "GameOver2D.h"
#include "SkyBox.h"

class Camera;

class GameScene : public Scene 
{
public:
	GameScene();
	~GameScene();
	void Init();
	void Update();
	void Render();
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
	Player* GetPlayer(){ return &player; }
	Boss* GetBoss() { return &boss; }
	EnemyManager* GetEnemyManager() { return &enemy; }
	void AddPlayerTama(Tama* tama)
	{
		playertama.push_back(tama);
	}
	void AddBossTama(BossTama* tama)
	{
		bosstama.push_back(tama);
	}
	void AddEnemyTama(EnemyTama* tama)
	{
		enemytama.push_back(tama);
	}
	/*!
	* @brief	プレイヤーが放った弾のリストを取得。
	* @code
	サンプルコード
	const std::list<Bullet*>& bulletList = game->GetPlayerBullet();
	for(auto bullet : bulletList){
	bullet->Render();
	}
	@endcode
	*/
	const std::vector<Tama*>& GetPlayerTama()
	{
		return playertama;
	}
	const std::vector<BossTama*>& GetBossTama()
	{
		return bosstama;
	}
	const std::vector<EnemyTama*>& GetEnemyTama()
	{
		return enemytama;
	}
	
private:
	Bloom				bloom;
	Map					map;
	EnemyManager		enemy;
	PlayerCamera		playcam;
	Player				player;
	std::vector<Tama*>  playertama;
	std::vector<BossTama*>  bosstama;
	std::vector<EnemyTama*> enemytama;
	Boss				boss;
	HpBar				hpB;
	BossHp				bossHp;
	Camera				c;
	Complete2D          comp;
	GameOver2D          over;
	SkyBox				sky;
	
	SoundSource bgm;
	
};
extern GameScene* game;
