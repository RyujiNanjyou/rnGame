#include "stdafx.h"
#include "TitleScene.h"
#include "SceneManager.h"


TitleScene::TitleScene()
{

}


TitleScene::~TitleScene()
{

}
void TitleScene::Init()
{
	c.Init();
	t.Init();
	
}
void TitleScene::Update()
{
	pad.Update();
	if (pad.IsTrigger(enButtonA))
	{
		SoundSource* se = new SoundSource;
		se->Init("Assets/Sound/select08.wav");
		se->Play(false);
		se->SetVolume(1.0f);
		scenemanager->ChangeScene(scenemanager->Scenes::GAME);
	}
}
void TitleScene::Render()
{
	t.Render(c.GetViewMatrix(), c.GetProjectionMatrix());
}