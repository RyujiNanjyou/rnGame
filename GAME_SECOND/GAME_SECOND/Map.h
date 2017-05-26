#pragma once
#include "MapChip.h"

/*!
* @brief	�}�b�v�N���X�B
*/
class Map{
public:

	Map();
	~Map();
	void Start();
	void Update();
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		const D3DXVECTOR4 diffuseLightDirection,
		const D3DXVECTOR4 diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int lightnum
		);

private:
	D3DXMATRIX				mWorld;			//���[���h�s��B
	D3DXMATRIX				mRotation;
	std::vector<MapChip*> mapChipList;	//�}�b�v�`�b�v�̃��X�g�B
};