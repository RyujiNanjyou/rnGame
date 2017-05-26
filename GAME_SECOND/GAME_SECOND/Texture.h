#pragma once
class Texture
{
public:
	
	Texture()
	{
	}
	~Texture()
	{
		Release();
	}
	void SetTextureDX(LPDIRECT3DTEXTURE9 tex)
	{

		if (tex != nullptr) {
			if (this->tex != nullptr) {
				tex->Release();
			}
			this->tex = tex;
			this->tex->AddRef();
			ComputeTexSize();
		}
	}
	LPDIRECT3DTEXTURE9 GetTextureDX() const
	{
		return tex;
	}
	
	void Release()
	{
		if (tex) {
			tex->Release();
			tex = nullptr;
		}
		
	}
	//�e�N�X�`���̕����擾�B
	int GetWidth() const
	{
		return texW;
	}
	//�e�N�X�`���̍������擾�B
	int GetHeight() const
	{
		return texH;
	}
	
	/*!
	* @brief	�e�N�X�`�������[�h�B
	*/
	bool Load(const char* fileName, bool isCubeMap = false);

private:
	//�e�N�X�`���T�C�Y���v�Z�B
	void ComputeTexSize()
	{
		D3DSURFACE_DESC desc;
		if (tex) {
			tex->GetLevelDesc(0, &desc);
		}
		texW = desc.Width;
		texH = desc.Height;
	}
private:
	LPDIRECT3DTEXTURE9	tex = nullptr;		//!<�e�N�X�`���B
	
	int texW = 0;								//!<�e�N�X�`���̉����B
	int texH = 0;								//!<�e�N�X�`���̏c���B
};




