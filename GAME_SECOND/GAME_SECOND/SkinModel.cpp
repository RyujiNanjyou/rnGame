#include "stdafx.h"
#include "SkinModelData.h"
#include "Light.h"
#include "GameScene.h"
#include "shadow.h"


extern UINT                 g_NumBoneMatricesMax;
extern D3DXMATRIXA16*       g_pBoneMatrices;

LPDIRECT3DTEXTURE9 shadow = NULL;


void SkinModel::DrawMeshContainer(
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
	)
{
	D3DXMESHCONTAINER_DERIVED* pMeshContainer = (D3DXMESHCONTAINER_DERIVED*)pMeshContainerBase;
	D3DXFRAME_DERIVED* pFrame = (D3DXFRAME_DERIVED*)pFrameBase;
	UINT iAttrib;
	LPD3DXBONECOMBINATION pBoneComb;

	D3DXMATRIXA16 matTemp;
	D3DCAPS9 d3dCaps;
	pd3dDevice->GetDeviceCaps(&d3dCaps);
	D3DXMATRIX viewProj;
	D3DXMatrixMultiply(&viewProj, &viewMatrix, &projMatrix);
	if (pMeshContainer->pSkinInfo != NULL) {
		//��ȊO�̃��f���̕`��
		if (isDrawToShadowMap == TRUE)
		{
			//�e�p�̃e�N�j�b�N��ݒ�
			pEffect->SetTechnique("SkinModelDrowToShadowMap");
		}
		else
		{
			pEffect->SetTechnique("SkinModel");
		}
	}
	else {
		//��̃��f���̕`��
		if (isDrawToShadowMap == TRUE)
		{
			//�e�p�̃e�N�j�b�N��ݒ�
			pEffect->SetTechnique("NoSkinModelDrowToShadowMap");
		}
		else
		{
			pEffect->SetTechnique("NoSkinModel");
		}
	}

	//���C�g�r���[�v���W�F�N�V�����s��̌v�Z�B
	D3DXMATRIX LVP;
	LVP = game->Getshadow()->Getlvpmatrix();

	//�萔���W�X�^�ɐݒ肷��J���[�B
	D3DXVECTOR4 color(1.0f, 0.0f, 0.0f, 1.0f);
	//���[���h�s��̓]���B
	pEffect->SetMatrix("g_worldMatrix", &worldMatrix);
	//�r���[�s��̓]���B
	pEffect->SetMatrix("g_viewMatrix", &viewMatrix);
	//�v���W�F�N�V�����s��̓]���B
	pEffect->SetMatrix("g_projectionMatrix", &projMatrix);
	//��]�s���]���B
	pEffect->SetMatrix("g_rotationMatrix", &rotationMatrix);
	//���C�g�̌�����]���B
	pEffect->SetVectorArray("g_diffuseLightDirection", &light->GetDLDirecton(), LIGHT_NUM);
	////���C�g�̃J���[��]���B
	pEffect->SetVectorArray("g_diffuseLightColor", &light->GetDLColor(), LIGHT_NUM);
	////������ݒ�B
	pEffect->SetVector("g_ambientLight",&light->Getamb());
	//�e�̃t���O��]���B
	pEffect->SetInt("g_ShadowReceiverFlag", ShadowReceiverFlag);
	//Z�v���p�X�̃t���O�]���B
	pEffect->SetInt("g_ZPrepassFlag",isZPrepass);
	//���C�g�r���[�v���W�F�N�V�����s��̓]���B
	pEffect->SetMatrix("g_mLVP", &LVP);
	//�r���[�v���W�F�N�V�����B
	pEffect->SetMatrix("g_mViewProj", &viewProj);
	//���_�B
	pEffect->SetVector("vEyePos", &(D3DXVECTOR4)game->GetCamera().GetEyePt());
	//�e��`�悵�Ă��郌���_�[�^�[�Q�b�g�̃e�N�X�`�����擾�B

	if (ShadowReceiverFlag == TRUE)
	{
		pEffect->SetTexture("g_shadowTexture", shadow);
	}
	//���ʂ̒萔���W�X�^��ݒ�
	{
		//���C�g
		pEffect->SetValue(
			"g_light",
			light,
			sizeof(Light)
			);
		if (isNormalMap == true)
		{
			if (normalMap != NULL)
			{
				//�@���}�b�v������ꍇ
				pEffect->SetTexture("g_normalTexture", normalMap);
				pEffect->SetInt("g_hasNormalMap", isNormalMap);
			}
		}
		else
		{
			//�@���}�b�v���Ȃ��ꍇ
			pEffect->SetTexture("g_normalTexture", NULL);
			pEffect->SetInt("g_hasNormalMap", isNormalMap);
		}
		if (isSpecularMap == true)
		{
			if (specularMap != NULL) {
				//�X�y�L�����}�b�v������̂ŁA�V�F�[�_�[�ɓ]������B
				pEffect->SetTexture("g_specularTexture", specularMap);
				//�X�y�L�����}�b�v�̂���A�Ȃ��̃t���O��true�ɂ���B
				pEffect->SetInt("g_isHasSpecularMap", isSpecularMap);
			}
		}
		else
		{
			//�X�y�L�����}�b�v�̂���A�Ȃ��̃t���O��false�ɂ���B
			pEffect->SetTexture("g_specularTexture", NULL);
			pEffect->SetInt("g_isHasSpecularMap", isSpecularMap);
		}

		if (isDarkTextuer == true)
		{
			
			if (darkTex != NULL) {
				//�_�[�N�e�N�X�`��������̂ŁA�V�F�[�_�[�ɓ]������B
				pEffect->SetTexture("g_darkTexture", darkTex);
				//�_�[�N�e�N�X�`���̂���A�Ȃ��̃t���O��true�ɂ���B
				pEffect->SetInt("g_isHasDarkTexture", isDarkTextuer);
			}
		}
		else
		{
			//�_�[�N�e�N�X�`���̂���A�Ȃ��̃t���O��false�ɂ���B
			pEffect->SetTexture("g_darkTexture", NULL);
			pEffect->SetInt("g_isHasDarkTexture", isDarkTextuer);
		}

		if (pMeshContainer->pSkinInfo != NULL)
		{
			//�X�L�����L��B
			pBoneComb = reinterpret_cast<LPD3DXBONECOMBINATION>(pMeshContainer->pBoneCombinationBuf->GetBufferPointer());
			for (iAttrib = 0; iAttrib < pMeshContainer->NumAttributeGroups; iAttrib++)
			{
				// first calculate all the world matrices
				for (DWORD iPaletteEntry = 0; iPaletteEntry < pMeshContainer->NumPaletteEntries; ++iPaletteEntry)
				{
					DWORD iMatrixIndex = pBoneComb[iAttrib].BoneId[iPaletteEntry];
					if (iMatrixIndex != UINT_MAX)
					{
						D3DXMatrixMultiply(
							&g_pBoneMatrices[iPaletteEntry],
							&pMeshContainer->pBoneOffsetMatrices[iMatrixIndex],
							pMeshContainer->ppBoneMatrixPtrs[iMatrixIndex]
							);
						//D3DXMatrixMultiply(&g_pBoneMatrices[iPaletteEntry], &matTemp, &g_matView);
					}
				}


				pEffect->SetMatrixArray("g_mWorldMatrixArray", g_pBoneMatrices, pMeshContainer->NumPaletteEntries);
				pEffect->SetInt("g_numBone", pMeshContainer->NumInfl);
				// �f�B�t���[�Y�e�N�X�`���B
				pEffect->SetTexture("g_diffuseTexture", pMeshContainer->ppTextures[pBoneComb[iAttrib].AttribId]);

				// �{�[�����B
				pEffect->SetInt("CurNumBones", pMeshContainer->NumInfl - 1);
				D3DXMATRIX viewRotInv;
				D3DXMatrixInverse(&viewRotInv, NULL, &viewMatrix);
				viewRotInv.m[3][0] = 0.0f;
				viewRotInv.m[3][1] = 0.0f;
				viewRotInv.m[3][2] = 0.0f;
				viewRotInv.m[3][3] = 1.0f;
				D3DXMatrixTranspose(&viewRotInv, &viewRotInv);
				pEffect->SetMatrix("g_viewMatrixRotInv", &viewRotInv);
				pEffect->Begin(0, D3DXFX_DONOTSAVESTATE);
				pEffect->BeginPass(0);
				pEffect->CommitChanges();
				// draw the subset with the current world matrix palette and material state
				pMeshContainer->MeshData.pMesh->DrawSubset(iAttrib);
				pEffect->EndPass();
				pEffect->End();

			}
		}
		else
		{

			D3DXMATRIX mWorld;
			if (pFrame != NULL) {
				mWorld = pFrame->CombinedTransformationMatrix;
			}
			else {
				mWorld = worldMatrix;
			}

			pEffect->SetMatrix("g_worldMatrix", &mWorld);
			pEffect->SetMatrix("g_rotationMatrix", &rotationMatrix);
			pEffect->Begin(0, D3DXFX_DONOTSAVESTATE);
			pEffect->BeginPass(0);
			for (DWORD i = 0; i < pMeshContainer->NumMaterials; i++) {

				pEffect->SetTexture("g_diffuseTexture", pMeshContainer->ppTextures[i]);
				pEffect->CommitChanges();
				pMeshContainer->MeshData.pMesh->DrawSubset(i);
			}
			pEffect->EndPass();
			pEffect->End();
		}

	}

}
void SkinModel::DrawFrame(
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
	)
{
	LPD3DXMESHCONTAINER pMeshContainer;

	pMeshContainer = pFrame->pMeshContainer;
	while (pMeshContainer != NULL)
	{
		DrawMeshContainer(
			pd3dDevice,
			pMeshContainer,
			pFrame,
			pEffect,
			worldMatrix,
			rotationMatrix,
			viewMatrix,
			projMatrix,
			light,
			normalMap,
			specularMap,
			darkTex,
			isDrawToShadowMap,
			isZPrepass
			);

		pMeshContainer = pMeshContainer->pNextMeshContainer;
	}

	if (pFrame->pFrameSibling != NULL)
	{
		DrawFrame(
			pd3dDevice,
			pFrame->pFrameSibling,
			pEffect,
			worldMatrix,
			rotationMatrix,
			viewMatrix,
			projMatrix,
			light,
			normalMap,
			specularMap,
			darkTex,
			isDrawToShadowMap,
			isZPrepass
			);
	}

	if (pFrame->pFrameFirstChild != NULL)
	{
		DrawFrame(
			pd3dDevice,
			pFrame->pFrameFirstChild,
			pEffect,
			worldMatrix,
			rotationMatrix,
			viewMatrix,
			projMatrix,
			light,
			normalMap,
			specularMap,
			darkTex,
			isDrawToShadowMap,
			isZPrepass
			);
	}
}
SkinModel::SkinModel() :
skinModelData(nullptr),
light(nullptr),
pEffect(nullptr)
{
}
SkinModel::~SkinModel()
{

}

void SkinModel::Init(SkinModelData* modelData)
{
	ShadowReceiverFlag = false;
	isDrawToShadowMap = false;
	isNormalMap = false;
	isSpecularMap = false;
	skinModelData = modelData;
}
void SkinModel::UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale)
{
	D3DXMATRIX mTrans, mScale;
	D3DXMatrixScaling(&mScale, scale.x, scale.y, scale.z);
	D3DXMatrixTranslation(&mTrans, trans.x, trans.y, trans.z);
	D3DXMatrixRotationQuaternion(&rotationMatrix, &rot);
	worldMatrix = mScale * rotationMatrix * mTrans;

	if (skinModelData) {
		skinModelData->UpdateBoneMatrix(worldMatrix);	//�{�[���s����X�V�B
	}
}

void SkinModel::Draw(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix, bool isDrawToShadowMap,  bool isZPrepass)
{
	if (skinModelData)
	{
		DrawFrame(
			g_pd3dDevice,
			skinModelData->GetFrameRoot(),
			pEffect,
			worldMatrix,
			rotationMatrix,
			viewMatrix,
			projMatrix,
			light,
			normalMap,
			specularMap,
			darkTex,
			isDrawToShadowMap,
			isZPrepass
			);
	}
}

/*!
* @brief	�擪�̃��b�V�����擾�B
*/
LPD3DXMESH SkinModel::GetOrgMeshFirst() const
{
	return skinModelData->GetOrgMeshFirst();
}