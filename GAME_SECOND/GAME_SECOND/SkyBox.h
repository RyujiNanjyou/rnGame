#pragma once
#include "light.h"
#include "camera.h"
class SkyBox
{
public:
	SkyBox();
	~SkyBox();
	void Init();
	void Update();
    void Render();
private:
	SkinModelData skinmodeldata;
	SkinModel skinmodel;
	Light light;
	Camera camera;
};

