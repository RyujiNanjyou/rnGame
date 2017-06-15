#pragma once

#include "Scene.h"

class Scene;

using namespace std;
/*!
*@brief	マネージャー。
*/
class SceneManager
{
public:
	enum Scenes {
		TITLE = 0,
		SELECT,
		GAME,
		RESULT
	};
	/*!
	*@brief	コンストラクタ
	*/
	SceneManager()
	{
		scenes = NULL;
	}
	/*!
	*@brief	初期化
	*/
	void InitializeScene();
	/*!
	*@brief	更新
	*/
	void UpdateScene();
	/*!
	*@brief	描画
	*/
	void RenderScene();
	/*!
	*@brief	切り替え
	*/
	void ChangeScene(const int& key);
	
	/*void SetResult(bool flag)
	{
		resultflag = flag;
	}*/
	
	/*bool GetResult()
	{
		return resultflag;
	}*/
private:
	Scene* scenes;
	int nextScene = -1;
	//bool resultflag = 0;		//0はゴール、1はデス

};
extern SceneManager* scenemanager;