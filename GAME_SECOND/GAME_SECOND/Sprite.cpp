#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite()
//texture(nullptr),
//spriteEffect(nullptr)
{

}


Sprite::~Sprite()
{
	
}

void Sprite::Init(const char* TexPath)
{
	HRESULT hr = D3DXCreateTextureFromFileA(g_pd3dDevice, TexPath, &texture);

	SShapeVertex vb[] = {
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
	short index[]{
		0, 1, 2, 3
	};
	primitive.Create(
		Primitive::eTriangleStrip,
		4,
		sizeof(SShapeVertex),
		scShapeVertex_PT_Element,
		vb,
		4,
		D3DFMT_INDEX16,
		index
		);
	D3DSURFACE_DESC desc;
	if (texture) {
		texture->GetLevelDesc(0, &desc);
	}
	size.x = desc.Width;
	size.y = desc.Height;
	
	LPD3DXBUFFER  compileErrorBuffer = NULL;
	hr = D3DXCreateEffectFromFile(
		g_pd3dDevice,
		"Assets/Shader/ColorTexPrim.fx",
		NULL,
		NULL,
#ifdef _DEBUG
		D3DXSHADER_DEBUG,
#else
		D3DXSHADER_SKIPVALIDATION,
#endif
		NULL,
		&spriteEffect,
		&compileErrorBuffer
		);
	if (FAILED(hr)) {
		MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		std::abort();
	}
}
void Sprite::Update()
{
	
}
void Sprite::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	D3DXMATRIX m;
	D3DXVECTOR3 scale;
	scale.x = size.x / WINDOW_WIDTH;
	scale.y = size.y / WINDOW_HEIGHT;
	scale.z = 1.0f;
	D3DXMatrixScaling(&m, scale.x, scale.y, scale.z);
	D3DXMATRIX trans;
	D3DXVECTOR3 vectrans;
	vectrans.x = position.x / (WINDOW_WIDTH / 2);
	vectrans.y = position.y / (WINDOW_HEIGHT / 2);
	vectrans.z = 0.0f;
	D3DXVECTOR3 pivotoffset;
	pivotoffset.x = (size.x * (0.5f - pivot.x)) / (WINDOW_WIDTH / 2);
	pivotoffset.y = (size.y * (0.5f - pivot.y)) / (WINDOW_HEIGHT / 2);
	pivotoffset.z = 0.0f;
	D3DXVec3Add(&vectrans, &vectrans, &pivotoffset);
	D3DXMatrixTranslation(&trans, vectrans.x, vectrans.y, vectrans.z);
	D3DXMATRIX Rot;
	D3DXMatrixInverse(&Rot, NULL, &viewMatrix);
	Rot.m[3][0] = 0.0f;
	Rot.m[3][1] = 0.0f;
	Rot.m[3][2] = 0.0f;
	Rot.m[3][3] = 1.0f;

	m = m * Rot * trans * viewMatrix * projMatrix;
	//アルファブレンディングを有効にする。
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	spriteEffect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
	spriteEffect->BeginPass(0);
	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);

	spriteEffect->SetTechnique("ColorTexPrimAdd");

	spriteEffect->SetValue("g_mWVP", &m, sizeof(m));
	spriteEffect->SetTexture("g_texture", texture);
	spriteEffect->CommitChanges();

	g_pd3dDevice->SetStreamSource(0, primitive.GetVertexBuffer()->GetBody(), 0, primitive.GetVertexBuffer()->GetStride());
	g_pd3dDevice->SetIndices(primitive.GetIndexBuffer()->GetBody());
	g_pd3dDevice->SetVertexDeclaration(primitive.GetVertexDecl());
	g_pd3dDevice->DrawIndexedPrimitive(primitive.GetD3DPrimitiveType(), 0, 0, primitive.GetNumVertex(), 0, primitive.GetNumPolygon());
	spriteEffect->EndPass();
	spriteEffect->End();
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	//g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	//g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
	//g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}