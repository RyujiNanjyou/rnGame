#include "stdafx.h"
#include "TitleScene.h"
#include "Fade.h"
#include "SceneManager.h"


TitleScene::TitleScene()
{

}


TitleScene::~TitleScene()
{
}
void TitleScene::Init()
{
	fade->Start();
	title2D.Init();
	titlebgm.InitStreaming("Assets/Sound/game_maoudamashii_7_event43 (online-audio-converter.com).wav");
	titlebgm.Play(true);
	titlebgm.SetVolume(0.5f);
}
void TitleScene::Update()
{
	
	titlebgm.Update();
	pad.Update();
	switch (state)
	{
	case TitleScene::state_Run:
		if (pad.IsTrigger(enButtonA))
		{
			titlebgm.Stop();
			fade->StartFadeOut();
			state = state_FadeOut;

		}
		break;
	case TitleScene::state_FadeOut:
		if (!fade->IsExecute())
		{
			scenemanager->ChangeScene(scenemanager->Scenes::GAME);
		}
		break;

	}
	fade->Update();
}
void TitleScene::Render()
{
	title2D.Render();
	fade->PostRender();
}