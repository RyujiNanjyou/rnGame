#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "SceneManager.h"


void SceneManager::InitializeScene()
{
	ChangeScene(Scenes::TITLE);
}

void SceneManager::UpdateScene()
{
	if (scenes){
		scenes->Update();
	}
	if (nextScene != -1){
		if (scenes != NULL)
		{
			delete physicsworld;
			physicsworld = NULL;
			delete scenes;
		}
		if (nextScene == Scenes::TITLE)
		{
			scenes = new TitleScene;
		}
		if (nextScene == Scenes::GAME)
		{
			scenes = new GameScene;
		}
		scenes->Init();
		nextScene = -1;
	}
}

void SceneManager::RenderScene()
{
	scenes->Render();
}

void SceneManager::ChangeScene(const int& key)
{
	nextScene = key;
}
