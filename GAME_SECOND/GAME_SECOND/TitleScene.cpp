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
	atime += deltaTime;
	if (pad.IsTrigger(enButtonA))
	{
		titlese.reset(new SoundSource);
		titlese->Init("Assets/Sound/select08.wav");
		titlese->Play(false);
		titlese->SetVolume(0.8f);
		
		if (atime > 0.5f)
		{
			scenemanager->ChangeScene(scenemanager->Scenes::GAME);
		}
	}
	
		
	
}
void TitleScene::Render()
{
	t.Render(c.GetViewMatrix(), c.GetProjectionMatrix());
}