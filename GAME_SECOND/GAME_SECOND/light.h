#pragma once 
#include "stdafx.h"

#define		LIGHT_NUM  4
/*!
*@brief	ライト。
*/
class Light
{
public:
	/*!
	* @brief	コンストラクタ。
	*/
	Light()
	{
		//ディフューズディレクション。
		diffuseLightDirection[0] = D3DXVECTOR4(0.707f, -0.707f, 0.0f, 1.0f);
		diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
		diffuseLightDirection[2] = D3DXVECTOR4(-0.707f, -0.707f, 0.0f, 1.0f);
		diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

		//ディフューズライト。
		diffuseLightColor[0] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[1] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[2] = D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f);
		diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

		//環境光。
		ambientLight = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 0.5f);
	}
	/*!
	* @brief	デストラクタ。
	*/
	~Light()
	{

	}
	/*!
	* @brief	方向の取得。
	*/
	const D3DXVECTOR4& GetDLDirecton() const { return *diffuseLightDirection; } 
	/*!
	* @brief	カラーの取得。
	*/
	const D3DXVECTOR4& GetDLColor() const { return *diffuseLightColor; }
	/*!
	* @brief	コンストラクタ。
	*/
	const D3DXVECTOR4& Getamb() const { return ambientLight; }
	/*!
	* @brief	環境光の設定。
	*/
	void Setamb(const D3DXVECTOR4 a){ ambientLight = a; }
	/*!
	* @brief	ディレクションの設定。
	*/
	void SetDLDirecton(int n,D3DXVECTOR4 a) { diffuseLightDirection[n] = a; }
	/*!
	* @brief	カラーの設定。
	*/
	void SetDLColor(int n, D3DXVECTOR4 a) { diffuseLightColor[n] = a; }
	
private:

	D3DXVECTOR4 			diffuseLightDirection[LIGHT_NUM];	//ライトの方向。
	D3DXVECTOR4				diffuseLightColor[LIGHT_NUM];		//ライトの色。
	D3DXVECTOR4				ambientLight;						//環境光
};
