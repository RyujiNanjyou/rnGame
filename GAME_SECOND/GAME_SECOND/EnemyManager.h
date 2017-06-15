#pragma once

class Enemy;
/*!
*@brief	エネミーマネージャー。
*/
class EnemyManager
{
public:
	/*!
	*@brief	コンストラクタ。
	*/
	EnemyManager();
	/*!
	*@brief	デストラクタ。
	*/
	~EnemyManager();
	/*!
	*@brief	初期化。
	*/
	void Start();
	/*!
	*@brief	更新。
	*/
	void Update();
	/*!
	*@brief	描画。
	*/
	void Render(LPDIRECT3DDEVICE9 pd3dDevice,
		D3DXMATRIX viewMatrix,
		D3DXMATRIX projMatrix,
		const D3DXVECTOR4 diffuseLightDirection,
		const D3DXVECTOR4 diffuseLightColor,
		D3DXVECTOR4	 ambientLight,
		int lightnum
		);
	/*!
	*@brief	エネミーの取得。
	*/
	const std::vector<Enemy*>& GetEnemy(){ return enemyChipList; }
private:
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;		//回転行列。
	std::vector<Enemy*>		enemyChipList;	//チップのリスト。
	
};

