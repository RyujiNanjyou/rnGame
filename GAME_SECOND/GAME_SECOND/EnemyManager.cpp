#include "stdafx.h"
#include "Enemy.h"
#include "EnemyManager.h"
using namespace std;

namespace
{
	int damageEffectTime = 0;
	int dtime = 5;
	int changecount = 0;
}
namespace 
{
	struct EnemyChipLocInfo {
		const char*		modelName;		//���f���B
		D3DXVECTOR3		pos;			//���W�B
		D3DXQUATERNION	rotation;		//��]�B
	};
	//�}�b�v�`�b�v�̔z�u���̃e�[�u���B
	EnemyChipLocInfo enemyChipLocInfoTable[] =
	{
		#include "Enemyinfo.h"
	};
}
EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
	for (auto& enemyChip : enemyChipList)
	{
		delete enemyChip;
	}
}

void EnemyManager::Start()
{
	//�z�u��񂩂�}�b�v���\�z
	int tableSize = sizeof(enemyChipLocInfoTable) / sizeof(enemyChipLocInfoTable[0]);

	for (int i = 0; i < tableSize; i++)
	{
		
		//�}�b�v�`�b�v�𐶐�
		Enemy* enemyChip = new Enemy;
		if (enemyChip->GetDeathflag() == true)
		{
			enemyChip->Setpos(enemyChipLocInfoTable[i].pos);
			enemyChip->Setrot(enemyChipLocInfoTable[i].rotation);
			enemyChip->Init(g_pd3dDevice, enemyChipLocInfoTable[i].modelName);
			enemyChip->Start(enemyChip->Getpos(), enemyChip->Getrot());
			enemyChipList.push_back(enemyChip);
		}
	}
}
void EnemyManager::Update()
{

	for (auto& enemyChip : enemyChipList)
	{
		if (enemyChip->GetDeathflag() == true)
		{
			enemyChip->Update();
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		changecount = i;
	}
}

void EnemyManager::Render(LPDIRECT3DDEVICE9 pd3dDevice,
	const D3DXMATRIX& viewMatrix,
	const D3DXMATRIX& projMatrix,
	const D3DXVECTOR4& diffuseLightDirection,
	const D3DXVECTOR4& diffuseLightColor,
	const D3DXVECTOR4& ambientLight,
	int lightnum)
{
	for (auto& enemyChip : enemyChipList)
	{
		if (enemyChip->GetnowEnemyS() == enemyChip->IDOL)
		{
			if (enemyChip->GetDeathflag() == true)
			{
				enemyChip->Render(viewMatrix, projMatrix, false,false);
			}
		}

		if (enemyChip->GetnowEnemyS() == enemyChip->DAMAGE)
		{

			if (damageEffectTime == 0)
			{
				if (enemyChip->GetDeathflag() == true)
				{
					enemyChip->Render(viewMatrix, projMatrix, false,false);
				}
				damageEffectTime = 5;
				
				if (changecount == 10)
				{
					enemyChip->SetnowEnemyS(enemyChip->IDOL);
					changecount = 0;
				}
			}
			damageEffectTime--;
		}
		
		
		
	}
	
	
}

