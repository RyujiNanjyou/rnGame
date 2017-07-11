#pragma once
#include "Scene.h"
#include "PlayerCamera.h"
#include "bloom.h"
#include "Map.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Tama.h"
#include "BossTama.h"
#include "EnemyTama.h"
#include "Boss.h"
#include "HpBar.h"
#include "Complete2D.h"
#include "GameOver2D.h"
#include "SkyBox.h"
#include "LockOn2D.h"

class Camera;
/*!
*@brief	�Q�[����ʁB
*/
class GameScene : public Scene 
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	GameScene();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~GameScene();
	/*!
	* @brief	�������B
	*/
	void Init();
	/*!
	* @brief	�X�V�B
	*/
	void Update();
	/*!
	* @brief	�`��B
	*/
	void Render();
	/*!
	* @brief	�J�������擾�B
	*/
	const Camera& GetCamera() const
	{
		return playcam.GetCamera();
	}
	/*!
	* @brief	�Q�[���J�������擾�B
	*/
	const PlayerCamera& GetGameCamera() const
	{
		return playcam;
	}
	/*!
	* @brief	�v���C���[���擾�B
	*/
	Player* GetPlayer(){ return &player; }
	/*!
	* @brief	�{�X�̎擾
	*/
	Boss* GetBoss() { return &boss; }
	/*!
	* @brief	�G�l�~�[�Ǘ��N���X�̎擾
	*/
	EnemyManager* GetEnemyManager() { return &enemy; }
	/*!
	* @brief	�v���C���[�e�̒ǉ�
	*/
	void AddPlayerTama(Tama* tama)
	{
		playertama.push_back(tama);
	}
	/*!
	* @brief	�{�X�e�̒ǉ�
	*/
	void AddBossTama(BossTama* tama)
	{
		bosstama.push_back(tama);
	}
	/*!
	* @brief	�G�l�~�[�e�̒ǉ�
	*/
	void AddEnemyTama(EnemyTama* tama)
	{
		enemytama.push_back(tama);
	}
	/*!
	* @brief	�v���C���[���������e�̃��X�g���擾�B
	*/
	const std::vector<Tama*>& GetPlayerTama() const
	{
		return playertama;
	}
	/*!
	* @brief	�{�X���������e�̃��X�g���擾
	*/
	const std::vector<BossTama*>& GetBossTama() const
	{
		return bosstama;
	}
	/*!
	* @brief	�G�l�~�[���������e�̃��X�g���擾
	*/
	const std::vector<EnemyTama*>& GetEnemyTama() const
	{
		return enemytama;
	}
	LockOn2D* GetlockOn()  { return &lock2D; }
private:
	Bloom					bloom;//�u���[��
	Map						map;//�}�b�v
	EnemyManager			enemy;//�G�l�~�[�}�l�[�W���[
	PlayerCamera			playcam;//�Q�[���J����
	Player					player;//�v���C���[
	std::vector<Tama*>		playertama;//�v���C���[�e���X�g
	std::vector<BossTama*>  bosstama;//�{�X�e���X�g
	std::vector<EnemyTama*> enemytama;//�G�l�~�[�e���X�g
	Boss					boss;//�{�X
	HpBar					hpB;//�q�b�g�|�C���g�o�[2D
	Camera					camera2D;//2D�J����
	Complete2D				comp;//�R���v���[�g��2D
	GameOver2D				over;//�Q�[���I�[�o�[��2D
	LockOn2D				lock2D;
	SkyBox					sky;//�w�i
	SoundSource				bgm;//�X�e�[�W�T�E���h
	SoundSource				bossbgm;//�{�X��T�E���h
	
};
extern GameScene* game;
