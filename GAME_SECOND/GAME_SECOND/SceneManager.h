#pragma once

#include "Scene.h"

class Scene;

using namespace std;



class SceneManager
{
public:
enum Scenes { TITLE = 0, SELECT, GAME, RESULT };
	SceneManager()
	{
		scenes = NULL;
	}
	void InitializeScene();
	void UpdateScene();
	void RenderScene();
	void ChangeScene(const int& key);
	void SetResult(bool flag)
	{
		resultflag = flag;
	}
	bool GetResult()
	{
		return resultflag;
	}
private:
	Scene* scenes;
	int nextScene = -1;
	bool resultflag = 0;		//0�̓S�[���A1�̓f�X

};
extern SceneManager* scenemanager;