#pragma once
#include "Primitive.h"
#include "SceneManager.h"
#include "Texture.h"
/*!
*@brief	���W��UV���W
*/
struct SShapeVertex {
	float		pos[4];
	float		uv[2];
};
static const D3DVERTEXELEMENT9 scShapeVertex_PT_Element[] = {
	{ 0, 0, D3DDECLTYPE_FLOAT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 16, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	D3DDECL_END()
};
/*!
*@brief 2D�B
*/
class Sprite
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Sprite();
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	~Sprite();
	/*!
	*@brief	�������B
	*@param[in] TexPath	�e�N�X�`���[�p�X
	*/
	void Init(const char* TexPath) ;
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*/
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
	/*!
	* @brief	���W�̐ݒ�
	*/
	void Setpos(D3DXVECTOR2& pos) { position = pos; }
	/*!
	* @brief	�T�C�Y�̐ݒ�
	*/
	void Setsize(D3DXVECTOR2& s){ size = s; }
	/*!
	* @brief	�s�{�b�g�̐ݒ�
	*/
	void SetPivot(const D3DXVECTOR2& pivot){ this->pivot = pivot; }
	/*!
	* @brief	���W�̎擾
	*/
	const D3DXVECTOR2& Getpos()const { return position; }
	/*!
	* @brief	�T�C�Y�̎擾
	*/
	const D3DXVECTOR2& Getsize()const { return size;}
	/*!
	* @brief	���̎擾
	*/
	float Getalpha()const { return alpha; }
	/*!
	* @brief	���̐ݒ�
	*/
	void Setalpha(float a) { alpha = a; }
private:
	Primitive			primitive;			//�v���~�e�B�u�B
	LPDIRECT3DTEXTURE9  texture = nullptr;			//�e�N�X�`���B
	ID3DXEffect*		spriteEffect = nullptr;		//�V�F�[�_�[�G�t�F�N�g�B
	D3DXVECTOR2			size = D3DXVECTOR2(1.0f, 1.0f);//�T�C�Y
	D3DXVECTOR2			pivot = D3DXVECTOR2(0.5f, 0.5f);//�s�{�b�g
	D3DXVECTOR2			position = D3DXVECTOR2(0.0f, 0.0f);//���W
	D3DXQUATERNION		rotation;//��]�B
	
	float				alpha = 1.0f;//��
};

