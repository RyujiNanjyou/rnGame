#pragma once
#include "camera.h"

class Player;

//�Q�[���J����
class PlayerCamera
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	PlayerCamera();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~PlayerCamera();
	/*!
	*@brief	�������B
	*@param[in] player�@�J�����ɒǔ����Ăق����I�u�W�F�N�g���w��
	*/
	void Start(Player* player);
	/*!
	*@brief	�X�V�̑O�̍X�V�B
	*/
	void PreUpdate();
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	//�J�������擾�B
	const Camera& GetCamera() const
	{
		return camera;
	}
	//�J�����̕������擾�B
	D3DXVECTOR3 GetCameraDir() const
	{
		return cameraDir;
	}
private:
	//�J�������X�V�B
	void UpdateCamera();
Camera		camera;
	Player*		player;			//�Ǐ]����v���C���[�B
	D3DXVECTOR4 targetOffset;	//�����_�̃I�t�Z�b�g�B
	D3DXVECTOR4 toEyePos;		//�����_���王�_�܂ł̃x�N�g���B	
	D3DXVECTOR3 cameraDir;		//�J�����̕����B
};


