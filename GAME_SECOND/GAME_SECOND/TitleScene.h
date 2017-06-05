#pragma once
#include "Scene.h"
#include "Title.h"
#include "camera.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
	void Init();
	void Update();
	void Render();
private:
	Title t;
	Camera c;
	std::unique_ptr<SoundSource> titlese;
	SoundSource titlebgm;
	float atime = 0.0f;
	float deltaTime = 1.0f / 60.0f;
};

