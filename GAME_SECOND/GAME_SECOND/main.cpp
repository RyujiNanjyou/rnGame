#include "stdafx.h"
#include "RenderTarget.h"
#include "Primitive.h"
#include "GameScene.h"
#include "SceneManager.h"
#include "SoundEngine.h"
//-----------------------------------------------------------------------------
// �O���[�o���ϐ��B
//-----------------------------------------------------------------------------
GameScene* game;
SceneManager* scenemanager;
RenderTarget* rendertarget;
SoundEngine* soundengine;
Primitive*	quadPrimitive;			//�l�p�`�̔|���v���~�e�B�u�B
LPD3DXEFFECT copyEffect;			//�R�s�[���s���V�F�[�_�[�B
LPD3DXEFFECT monochromeEffect;		//���m�N���t�B���^�[��������V�F�[�_�[�B
//-----------------------------------------------------------------------------
// �|����`��B
//-----------------------------------------------------------------------------
void DrawQuadPrimitive()
{
	// ���_�X�g���[��0�Ԃɔ|���̒��_�o�b�t�@��ݒ肷��B
	g_pd3dDevice->SetStreamSource(
		0,												//���_�X�g���[���̔ԍ��B
		quadPrimitive->GetVertexBuffer()->GetBody(),	//���_�o�b�t�@�B
		0,												//���_�o�b�t�@�̓ǂݍ��݂��J�n����I�t�Z�b�g�̃o�C�g���B
		//����͐擪����ǂݍ��ނ̂�0�ł����B
		quadPrimitive->GetVertexBuffer()->GetStride()	//���_����̃T�C�Y�B�P�ʂ̓o�C�g�B
		);
	// �C���f�b�N�X�o�b�t�@��ݒ�B
	g_pd3dDevice->SetIndices(quadPrimitive->GetIndexBuffer()->GetBody());
	// ���_��`��ݒ肷��B
	g_pd3dDevice->SetVertexDeclaration(quadPrimitive->GetVertexDecl());
	//�@�������������̂ŕ`��B
	g_pd3dDevice->DrawIndexedPrimitive(
		quadPrimitive->GetD3DPrimitiveType(),	//�v���~�e�B�u�̎�ނ��w�肷��B
		0,										//�x�[�X���_�C���f�b�N�X�B0�ł����B
		0,										//�ŏ��̒��_�C���f�b�N�X�B0�ł����B
		quadPrimitive->GetNumVertex(),			//���_�̐��B
		0,										//�J�n�C���f�b�N�X�B0�ł����B
		quadPrimitive->GetNumPolygon()			//�v���~�e�B�u�̐��B
		);
}
//-----------------------------------------------------------------------------
// Name:���C�������_�����O�^�[�Q�b�g���������B
//-----------------------------------------------------------------------------
void InitMainRenderTarget()
{
	rendertarget = new RenderTarget;
	rendertarget->Create(
		WINDOW_WIDTH,			//�����_�����O�^�[�Q�b�g�̕��ƍ����̓t���[���o�b�t�@�Ɠ����ɂ��Ă����B(�K�����������ł���K�v�͂Ȃ��I�I�I)
		WINDOW_HEIGHT,
		1,							//�~�b�v�}�b�v���x���B�����1�ł����B�~�b�v�}�b�v�o���Ă܂����H
		D3DFMT_A16B16G16R16F,			//�����_�����O�^�[�Q�b�g�̃t�H�[�}�b�g�B�����R8G8B8A8��32bit���w�肷��B
		D3DFMT_D24S8,				//�f�v�X�X�e���V���o�b�t�@�̃t�H�[�}�b�g�B��ʓI��16bit��24bit�t�H�[�}�b�g���g���邱�Ƃ������B�����24bit�t�H�[�}�b�g���g���B
		D3DMULTISAMPLE_NONE,		//�}���`�T���v�����O�̎�ށB����̓}���`�T���v�����O�͍s��Ȃ��̂�D3DMULTISAMPLE_NONE�ł����B
		0							//�}���`�T���v�����O�̕i�����x���B����̓}���`�T���v�����O�͍s��Ȃ��̂�0�ł����B
		);
}
//-----------------------------------------------------------------------------
// Name:�|���̏������B
//-----------------------------------------------------------------------------
void InitQuadPrimitive()
{
	quadPrimitive = new Primitive;
	//���_�̍\���́B
	struct SVertex {
		float pos[4];	//���_���W�B
		float uv[2];		//UV���W�B
	};
	//���_�o�b�t�@�B
	SVertex vertexBuffer[] = {
		{
			-1.0f, 1.0f, 0.0f, 1.0f,
			0.0f, 0.0f
		},
		{
			1.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f
		},
		{
			-1.0f, -1.0f, 0.0f, 1.0f,
			0.0f, 1.0f
		},
		{
			1.0f, -1.0f, 0.0f, 1.0f,
			1.0f, 1.0f
		},
	};
	//���_���C�A�E�g�B���_�o�b�t�@�̍\�����ǂ̂悤�ɂȂ��Ă��邩��GPU�ɋ����邽�߂̂��́B
	static const D3DVERTEXELEMENT9 scShapeVertex_PT_Element[] = {
		//���_�X�g���[����0�Ԗڂ�0�o�C�g�ڂ���float�^��4���̃f�[�^�͍��W(D3DDECLUSAGE_POSITION)�ł��邱�Ƃ������Ă���B
		{ 0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
		//���_�X�g���[����0�Ԗڂ�16�o�C�g�ڂ���float�^��2���̃f�[�^��UV���W(D3DDECLUSAGE_TEXCOORD)�ł��邱�Ƃ������Ă���B
		{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
		D3DDECL_END()
	};
	//�C���f�b�N�X�o�b�t�@�B
	unsigned short indexBuffer[] = { 0, 1, 2, 3 };
	quadPrimitive->Create(
		Primitive::eTriangleStrip,	//����̓v���~�e�B�u�̎�ނ̓g���C�A���O���X�g���b�v�B
		4,							//���_�̐��B�l�p�`�̔|���Ńg���C�A���O���X�g���b�v�Ȃ̂łS�B
		sizeof(SVertex),			//���_�X�g���C�h�B��̒��_�̑傫���B�P�ʂ̓o�C�g�B
		scShapeVertex_PT_Element,	//���_���C�A�E�g�B
		vertexBuffer,				//���_�o�b�t�@�B
		4,							//�C���f�b�N�X�̐��B
		D3DFMT_INDEX16,				//�C���f�b�N�X�o�b�t�@�̃t�H�[�}�b�g�B�����16bit�t�H�[�}�b�g���w�肷��B
		//�C���f�b�N�X�̐���65536�ȉ��̏ꍇ��16bit�ł������A����𒴂���ꍇ��D3DFMT_INDEX32���w�肷��B
		indexBuffer					//�C���f�b�N�X�o�b�t�@�B
		);
}
//-----------------------------------------------------------------------------
// Name:���C�������_�����O�^�[�Q�b�g�̓��e�����݂̃����_�����O�^�[�Q�b�g�ɃR�s�[�B
//-----------------------------------------------------------------------------
void CopyMainRTToCurrentRT()
{

	// Z�e�X�g�Ŏ��s���Ă�������獢��̂ŁAZ�e�X�g�͖����ɂ��Ă����B
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
	// ���u�����h������Ȃ��B
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	// ���_�X�g���[��0�Ԃɔ|���̒��_�o�b�t�@��ݒ肷��B
	g_pd3dDevice->SetStreamSource(
		0,												//���_�X�g���[���̔ԍ��B
		quadPrimitive->GetVertexBuffer()->GetBody(),	//���_�o�b�t�@�B
		0,												//���_�o�b�t�@�̓ǂݍ��݂��J�n����I�t�Z�b�g�̃o�C�g���B
		//����͐擪����ǂݍ��ނ̂�0�ł����B
		quadPrimitive->GetVertexBuffer()->GetStride()	//���_����̃T�C�Y�B�P�ʂ̓o�C�g�B
		);

	LPD3DXEFFECT shader = copyEffect;			//�R�s�[���s���V�F�[�_�[���g���ꍇ�͂�����B
	//LPD3DXEFFECT shader = monochromeEffect;		// ���m�N���t�B���^�[��������ꍇ�͂�������g�p����B
	//�V�F�[�_�[��ݒ�B
	shader->SetTechnique("Default");
	shader->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
	shader->BeginPass(0);
	//�V�[���e�N�X�`����ݒ肷��
	shader->SetTexture("g_tex", rendertarget->GetTexture());
	//�萔���W�X�^�ւ̕ύX���R�~�b�g����B
	shader->CommitChanges();
	DrawQuadPrimitive();
	shader->EndPass();
	shader->End();
	// �ύX���������_�����O�X�e�[�g�����ɖ߂��B
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
}
//-----------------------------------------------------------------------------
// Name: �V�F�[�_�[�����[�h�B
//-----------------------------------------------------------------------------
void LoadShaders()
{
	//�R�s�[���s���V�F�[�_�[�����[�h�B
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	HRESULT hr = D3DXCreateEffectFromFile(
		g_pd3dDevice,
		"Assets/Shader/Copy.fx",
		NULL,
		NULL,
#ifdef _DEBUG
		D3DXSHADER_DEBUG,
#else
		D3DXSHADER_SKIPVALIDATION,
#endif
		NULL,
		&copyEffect,
		&compileErrorBuffer
		);
	if (FAILED(hr)) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		std::abort();
	}
	//���m�N���t�B���^�[���s���V�F�[�_�[�����[�h�B
	hr = D3DXCreateEffectFromFile(
		g_pd3dDevice,
		"Assets/Shader/MonochromeFilter.fx",
		NULL,
		NULL,
#ifdef _DEBUG
		D3DXSHADER_DEBUG,
#else
		D3DXSHADER_SKIPVALIDATION,
#endif
		NULL,
		&monochromeEffect,
		&compileErrorBuffer
		);
	if (FAILED(hr)) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		std::abort();
	}
}
//-----------------------------------------------------------------------------
// Name: �Q�[�����������B
//-----------------------------------------------------------------------------
void Init()
{
	//���C�������_�����O�^�[�Q�b�g���쐬����B
	InitMainRenderTarget();
	//�l�p�`�̔|���v���~�e�B�u���쐬�B
	InitQuadPrimitive();
	//�V�F�[�_�[�����[�h�B
	LoadShaders();

	game = new GameScene;

	scenemanager = new SceneManager;
	scenemanager->InitializeScene();
	soundengine = new SoundEngine;
	soundengine->Init();

}
/*!-----------------------------------------------------------------------------
*@brief	�X�V�����B
-----------------------------------------------------------------------------*/
void Update()
{
	scenemanager->UpdateScene();
	soundengine->Update();
}
//-----------------------------------------------------------------------------
// Name: �`�揈���B
//-----------------------------------------------------------------------------
VOID Render()
{
	//�V�[���̕`��J�n�B
	g_pd3dDevice->BeginScene();

	LPDIRECT3DSURFACE9 frameBufferRT;
	LPDIRECT3DSURFACE9 frameBufferDS;
	g_pd3dDevice->GetRenderTarget(0, &frameBufferRT);		//���X�̃����_�����O�^�[�Q�b�g��ۑ��B��Ŗ߂��K�v������̂ŁB
	g_pd3dDevice->GetDepthStencilSurface(&frameBufferDS);	//���X�̃f�v�X�X�e���V���o�b�t�@��ۑ��B��Ŗ߂��K�v������̂ŁB
	 //�����_�����O�^�[�Q�b�g���t���[���o�b�t�@����ύX����B
	g_pd3dDevice->SetRenderTarget(
		0,									//���Ԗڂ̃����_�����O�^�[�Q�b�g��ݒ肷�邩�̈����B�����0�ł����B
		rendertarget->GetRenderTarget()	//�ύX���郌���_�����O�^�[�Q�b�g�B
		);
	 //�f�v�X�X�e���V���o�b�t�@���ύX����B
	g_pd3dDevice->SetDepthStencilSurface(rendertarget->GetDepthStencilBuffer());
	 //�����_�����O�^�[�Q�b�g���N���A�B
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
	//model��`��B
	
	scenemanager->RenderScene();


	//�V�[���̕`�悪���������̂Ń����_�����O�^�[�Q�b�g���t���[���o�b�t�@�ɖ߂��B
	g_pd3dDevice->SetRenderTarget(0, frameBufferRT);
	g_pd3dDevice->SetDepthStencilSurface(frameBufferDS);
	 //�Q�ƃJ�E���^�������Ă���̂ŊJ���B
	frameBufferRT->Release();
	frameBufferDS->Release();
	// �I�t�X�N���[�������_�����O�����G���t���[���o�b�t�@�ɓ\��t����B
	CopyMainRTToCurrentRT();
	// �V�[���̕`��I���B
	g_pd3dDevice->EndScene();
	// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���B
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
//-----------------------------------------------------------------------------
//�Q�[�����I������Ƃ��ɌĂ΂�鏈���B
//-----------------------------------------------------------------------------
void Terminate()
{
	copyEffect->Release();
	g_pd3dDevice->Release();
	effectmanager->Release(); 
	rendertarget->Release();
	delete scenemanager;
	delete game;
	delete rendertarget;
	delete quadPrimitive;
	
}