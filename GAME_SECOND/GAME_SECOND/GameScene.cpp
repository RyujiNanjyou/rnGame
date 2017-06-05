#include "stdafx.h"
#include "camera.h"
#include "PlayerCamera.h"
#include "bloom.h"
#include "Map.h"
#include "shadow.h"
#include "GameScene.h"


GameScene::GameScene()
{

}

GameScene::~GameScene()
{
	physics.Release();
	for (auto tama : playertama) {
		delete tama;
	}
	for (auto tama : bosstama) {
		delete tama;
	}
}

void GameScene::Init()
{
	game = this;
	//•¨—ƒ[ƒ‹ƒh‚ð‰Šú‰»B
	physics.Init();
	c.Init();
	hpB.Init();
	bossHp.Init();
	comp.Init();
	over.Init();
	playcam.Start(&player);
	player.Init(g_pd3dDevice, "Assets/Model/unity");
	boss.Init(g_pd3dDevice, "Assets/Model/Boss");
	enemy.Start();
	map.Start();
	sky.Init();
	BaseTama* tama = new BaseTama;
	tama->Init(g_pd3dDevice, "Assets/Model/tama");
	shadow.Create(WINDOW_WIDTH, WINDOW_HEIGHT);

	bgm.InitStreaming("Assets/Sound/game_maoudamashii_4_field01 (online-audio-converter.com).wav");
	bgm.Play(true);
	bgm.SetVolume(0.8f);

	
}

void GameScene::Update()
{
	c.Update();
	hpB.Update();
	bossHp.Update();
	comp.Update();
	over.Update();
	playcam.PreUpdate();
	player.Update();
	playcam.Update();
	boss.Update();
	enemy.Update();
	pad.Update();
	map.Update();
	sky.Update();
	bgm.Update();
	auto bulletIt = playertama.begin();
	while (bulletIt != playertama.end()) {
		if (!(*bulletIt)->Update()) {
			//Ž€–S
			bulletIt = playertama.erase(bulletIt);
		}
		else {
			bulletIt++;
		}
	}
	auto bossbulletIt = bosstama.begin();
	while (bossbulletIt != bosstama.end()) {
		if (!(*bossbulletIt)->Update()) {
			//Ž€–S
			bossbulletIt = bosstama.erase(bossbulletIt);
		}
		else {
			bossbulletIt++;
		}
	}
	auto enemybulletIt = enemytama.begin();
	while (enemybulletIt != enemytama.end()) {
		if (!(*enemybulletIt)->Update()) {
			//Ž€–S
			enemybulletIt = enemytama.erase(enemybulletIt);
		}
		else {
			enemybulletIt++;
		}
	}
	D3DXVECTOR3 lightposition = player.Getpos() + D3DXVECTOR3(0.0f, 30.0f, 0.0f);
	shadow.SetLightPosition(lightposition);
	D3DXVECTOR3 lightDir = player.Getpos() - lightposition;
	D3DXVec3Normalize(&lightDir, &lightDir);
	shadow.SetLightDirection(lightDir);
	
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(0);
	}
}

void GameScene::Render()
{
	shadow.Render(
		&GetCamera().GetViewMatrix(),
		&GetCamera().GetProjectionMatrix()
		);
	
	player.Render(
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		false
		);
	boss.Render(
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		false
		);
	enemy.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		light.GetDLDirecton(),
		light.GetDLColor(),
		light.Getamb(),
		LIGHT_NUM
		);
	sky.Render();
	map.Render(g_pd3dDevice,
		GetCamera().GetViewMatrix(),
		GetCamera().GetProjectionMatrix(),
		light.GetDLDirecton(),
		light.GetDLColor(),
		light.Getamb(),
		LIGHT_NUM
		);

	for (auto tama : playertama)
	{
		tama->Render(
			GetCamera().GetViewMatrix(),
			GetCamera().GetProjectionMatrix(),
			false
			);
	}
	for (auto tama : bosstama)
	{
		tama->Render(
			GetCamera().GetViewMatrix(),
			GetCamera().GetProjectionMatrix(),
			false
			);
	}
	for (auto tama : enemytama)
	{
		tama->Render(
			GetCamera().GetViewMatrix(),
			GetCamera().GetProjectionMatrix(),
			false
			);
	}
	bloom.Render();
	hpB.Render(
		c.GetViewMatrix(),
		c.GetProjectionMatrix()
		);
	D3DXVECTOR3 to = player.Getpos() - boss.Getpos();
	if (D3DXVec3Length(&to) < 5.0f)
	{
		bossHp.Render(
			c.GetViewMatrix(),
			c.GetProjectionMatrix()
			);

	}
	if (boss.GetBossS() == boss.BossSTATE_DEAD)
	{
		comp.Render(
			c.GetViewMatrix(),
			c.GetProjectionMatrix()
			);
	}
	if (player.GetNowS() == player.STATE_DEAD)
	{	
		over.Render(
		c.GetViewMatrix(),
		c.GetProjectionMatrix()
		);

	}
	
}