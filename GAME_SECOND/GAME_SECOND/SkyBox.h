#pragma once
#include "light.h"
#include "camera.h"
/*!
*@brief	�w�i�B
*/
class SkyBox
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	SkyBox();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~SkyBox();
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
private:
	SkinModelData skinmodeldata;//�X�L�����f���f�[�^
	SkinModel skinmodel;//�X�L�����f��
	Light light;//���C�g
	Camera camera;//�J����
};

