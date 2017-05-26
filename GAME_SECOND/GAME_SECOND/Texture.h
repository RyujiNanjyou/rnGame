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
	//テクスチャの幅を取得。
	int GetWidth() const
	{
		return texW;
	}
	//テクスチャの高さを取得。
	int GetHeight() const
	{
		return texH;
	}
	
	/*!
	* @brief	テクスチャをロード。
	*/
	bool Load(const char* fileName, bool isCubeMap = false);

private:
	//テクスチャサイズを計算。
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
	LPDIRECT3DTEXTURE9	tex = nullptr;		//!<テクスチャ。
	
	int texW = 0;								//!<テクスチャの横幅。
	int texH = 0;								//!<テクスチャの縦幅。
};




