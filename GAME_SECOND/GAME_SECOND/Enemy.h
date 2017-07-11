#pragma once
#include "GameObject.h"
#include "MeshCollider.h"
#include "RigidBody.h"

class EnemyManager;
/*!
*@brief	�G�l�~�[�B
*/
class Enemy :public GameObject
{
public:
	enum EnemyS{IDOL = 0,DEATH,DAMAGE};
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Enemy();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Enemy();
	/*!
	*@brief	�������B
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	�������B
	*/
	void Start(D3DXVECTOR3 pos, D3DXQUATERNION rotation);
	/*!
	*@brief	�X�V�B
	*/
	bool Update() override;
	/*!
	*@brief	�_���[�W�B
	*/
	void Damage();
	/*!
	*@brief	�`��B
	*/
	void  Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	���b�N�I���ł��邩�B
	*/
	bool IsPossibleLockOn() 
	{
		return lock;
	}
	/*!
	*@brief	��Ԃ̐ݒ�B
	*/
	void SetnowEnemyS(EnemyS s) { nowEnemyS = s; }
	/*!
	*@brief	��Ԃ̎擾�B
	*/
	EnemyS GetnowEnemyS()const { return nowEnemyS; }
	/*!
	*@brief	���S�t���O�̎擾�B
	*/
	bool GetDeathflag()const { return deathflag; }
	float GetHeight()const  { return height; }
private:
	EnemyS nowEnemyS;
	int hp = 2;
	bool deathflag = true;
	bool damageEffect = false;
	bool lock = true;
	int damageTime = 0;
	int intervalTime = 0;
	float radius = 0.3f;
	float height = 0.7f;
	std::unique_ptr<SoundSource> enemyJumpse;
	std::unique_ptr<SoundSource> enemyAttackse;
	std::unique_ptr<SoundSource> bombse;

};

