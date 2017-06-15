#pragma once

class Enemy;
/*!
*@brief	�G�l�~�[�}�l�[�W���[�B
*/
class EnemyManager
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	EnemyManager();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~EnemyManager();
	/*!
	*@brief	�������B
	*/
	void Start();
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�`��B
	*/
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		const D3DXVECTOR4 diffuseLightDirection,
		const D3DXVECTOR4 diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int lightnum
		);
	/*!
	*@brief	�G�l�~�[�̎擾�B
	*/
	const std::vector<Enemy*>& GetEnemy(){ return enemyChipList; }
private:
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;		//��]�s��B
	std::vector<Enemy*>		enemyChipList;	//�`�b�v�̃��X�g�B
	
};

