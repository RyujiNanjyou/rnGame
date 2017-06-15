#pragma once

#include "Scene.h"

class Scene;

using namespace std;
/*!
*@brief	�}�l�[�W���[�B
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
	*@brief	�R���X�g���N�^
	*/
	SceneManager()
	{
		scenes = NULL;
	}
	/*!
	*@brief	������
	*/
	void InitializeScene();
	/*!
	*@brief	�X�V
	*/
	void UpdateScene();
	/*!
	*@brief	�`��
	*/
	void RenderScene();
	/*!
	*@brief	�؂�ւ�
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
	//bool resultflag = 0;		//0�̓S�[���A1�̓f�X

};
extern SceneManager* scenemanager;