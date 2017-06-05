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

	titlebgm.InitStreaming("Assets/Sound/game_maoudamashii_7_event43 (online-audio-converter.com).wav");
	titlebgm.Play(true);
	titlebgm.SetVolume(0.5f);
}
void TitleScene::Update()
{
	
	titlebgm.Update();
	pad.Update();
	if (pad.IsTrigger(enButtonA))
	{
		titlebgm.Stop();
		scenemanager->ChangeScene(scenemanager->Scenes::GAME);
	}
	
		
	
}
void TitleScene::Render()
{
	t.Render(c.GetViewMatrix(), c.GetProjectionMatrix());
}