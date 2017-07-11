#pragma once
#include "MapChip.h"

/*!
* @brief	�}�b�v�N���X�B
*/
class Map{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Map();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Map();
	/*!
	* @brief	�������B
	*/
	void Start();
	/*!
	* @brief	�X�V�B
	*/
	void Update();
	/*!
	* @brief	�`��B
	*/
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix,
		const D3DXVECTOR4& diffuseLightDirection,
		const D3DXVECTOR4& diffuseLightColor,
		const D3DXVECTOR4& ambientLight,
		int lightnum
		);

private:
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;		//��]�s��
	std::vector<MapChip*> mapChipList;	//�}�b�v�`�b�v�̃��X�g�B
};