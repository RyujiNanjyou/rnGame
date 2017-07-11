#pragma once
#include "Scene.h"
#include "Title.h"
#include "camera.h"
/*!
*@brief	タイトル画面。
*/
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void Update();
	void Render();
private:
	enum Title_State
	{
		state_Run,
		state_FadeOut
	};

	Title title2D;
	std::unique_ptr<SoundSource> titlese;
	SoundSource titlebgm;
	float atime = 0.0f;
	float deltaTime = 1.0f / 60.0f;

	Title_State state = state_Run;
};

