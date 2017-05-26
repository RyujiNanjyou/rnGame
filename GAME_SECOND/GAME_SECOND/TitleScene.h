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
};

