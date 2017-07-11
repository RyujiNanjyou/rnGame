/*!
*@brief	�X�L�����f��
*/
#pragma once

#include "Animation.h"

class SkinModelData;
class RenderContext;
class Light;

/*!
*@brief	�X�L�����f��
*/
class SkinModel
{
public:
	SkinModel();
	~SkinModel();
	/*!
	*@brief	������
	*/
	void Init(SkinModelData* modelData);
	/*!
	*@brief	�`��B
	*/
	void Draw(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix, bool isDrawToShadowMap, bool isZPrepass);
	/*!
	*@brief	���[���h�s����X�V�B
	*@details
	* ���CMotion�N���X�Ɉړ������܂��B
	*@param[in]		trans	���s�ړ��B
	*@param[in]		rot		��]�B
	*@param[in]		scale	�g��B
	*/
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);

	void DrawMeshContainer(
		IDirect3DDevice9* pd3dDevice,
		LPD3DXMESHCONTAINER pMeshContainerBase,
		LPD3DXFRAME pFrameBase,
		ID3DXEffect* pEffect,
		const D3DXMATRIX&worldMatrix,
		const D3DXMATRIX& rotationMatrix,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX&projMatrix,
		Light* light,
		LPDIRECT3DTEXTURE9	normalMap,
		LPDIRECT3DTEXTURE9 specularMap,
		LPDIRECT3DTEXTURE9 darkTex,
		bool isDrawToShadowMap,
		bool isZPrepass
	);

	void DrawFrame(
		IDirect3DDevice9* pd3dDevice,
		LPD3DXFRAME pFrame,
		ID3DXEffect* pEffect,
		const D3DXMATRIX& worldMatrix,
		const D3DXMATRIX& rotationMatrix,
		const D3DXMATRIX& viewMatrix,
		const D3DXMATRIX& projMatrix,
		Light* light,
		LPDIRECT3DTEXTURE9	normalMap,
		LPDIRECT3DTEXTURE9 specularMap,
		LPDIRECT3DTEXTURE9 darkTex,
		bool isDrawToShadowMap,
		bool isZPrepass
	);
	/*!
	*@brief	���C�g��ݒ�B
	*/
	void SetLight(Light* light)
	{
		this->light = light;
	}
	void SetShadowReceiverFlag(bool flag)
	{
		ShadowReceiverFlag = flag;
	}
	void SetDrawToShadowMap(bool flag)
	{
		isDrawToShadowMap = flag;
	}
	/*!
	*@brief �@���}�b�v�t���O��ݒ�B
	*/
	void SetNormalMapflag(bool flag)
	{
		isNormalMap = flag;
	}
	void SetSpecularMapflag(bool flag)
	{
		isSpecularMap = flag;
	}
	void SetDarkTextuerflag(bool flag)
	{
		isDarkTextuer = flag;
	}
	ID3DXEffect* GetEffect()
	{
		return pEffect;
	}
	void SetEffect(ID3DXEffect* effect)
	{
		pEffect = effect;
	}
	const D3DXMATRIX Getworld()const
	{
		return worldMatrix;
	}
	const D3DXMATRIX& GetRot() const
	{
		return rotationMatrix;
	}
	/*!
	* @brief	�擪�̃��b�V�����擾�B
	*/
	LPD3DXMESH GetOrgMeshFirst() const;
	/*!
	* @brief	�m�[�}���}�b�v�Z�b�g�B
	*/
	void SetNormalMap(LPDIRECT3DTEXTURE9 normal)
	{
		normalMap = normal;
	}
	/*!
	*@brief �X�y�L�����}�b�v��ݒ�B
	*/
	void SetSpecularMap(LPDIRECT3DTEXTURE9 specMap)
	{
		specularMap = specMap;
	}
	/*!
	* @brief	�_�[�N�e�N�X�`���Z�b�g�B
	*/
	void SetDarkTextuer(LPDIRECT3DTEXTURE9 specMap)
	{
		darkTex = specMap;
	}
	LPDIRECT3DTEXTURE9 GetNormal() const
	{
		return normalMap;
	}
	LPDIRECT3DTEXTURE9 GetSpec() const
	{
		return specularMap;
	}

	LPDIRECT3DTEXTURE9 GetDarkTextuer() const
	{
		return darkTex;
	}
private:
	D3DXMATRIX			worldMatrix;			//!<���[���h�s��B
	D3DXMATRIX			rotationMatrix;			//!<��]�s��B
	SkinModelData*		skinModelData;			//!<�X�L�����f���f�[�^�B
	ID3DXEffect*		pEffect;				//!<�G�t�F�N�g�B
	Animation			animation;				//!<�A�j���[�V�����B
	Light*				light;					//!<���C�g�B
	bool				ShadowReceiverFlag;
	bool				isDrawToShadowMap;
	bool				isNormalMap;			//<!�m�[�}���}�b�v�t���O
	bool				isSpecularMap;		//<!�X�y�L�����}�b�v�t���O
	bool				isDarkTextuer;
	LPDIRECT3DTEXTURE9	normalMap = NULL;				//<!�m�[�}���}�b�v�B
	LPDIRECT3DTEXTURE9  specularMap = NULL;				//<!�X�y�L�����}�b�v�B
	LPDIRECT3DTEXTURE9  darkTex = NULL;
};