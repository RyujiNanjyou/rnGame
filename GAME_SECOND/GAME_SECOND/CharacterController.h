/*!
 * @brief	キャラクタコントローラー。
 */

#pragma once

//#include "SphereCollider.h"
#include "CapsuleCollider.h"
#include "RigidBody.h"


#define PI 3.14159265358979323846f
	/*!
	 * @brief	キャラクタコントローラー。
	 */
class CharacterController{
public:
	CharacterController() {

	}
	~CharacterController()
	{

	}
	/*!
	 * @brief	初期化。
	 */
	void Init(float radius, float height, const D3DXVECTOR3& position);
	/*!
	 * @brief	実行。
	 */
	void Execute();
	/*!
	 * @brief	座標を取得。
	 */
	const D3DXVECTOR3& GetPosition() const
	{
		return position;
	}
	/*!
	 * @brief	座標を設定。
	 */
	void SetPosition(const D3DXVECTOR3& pos)
	{
		position = pos;
	}
	/*!
	 * @brief	移動速度を設定。
	 */
	void SetMoveSpeed(const D3DXVECTOR3& speed)
	{
		moveSpeed = speed;
	}
	/*!
	 * @brief	移動速度を取得。
	 */
	const D3DXVECTOR3& GetMoveSpeed() const
	{
		return moveSpeed;
	}
	/*!
	 * @brief	ジャンプさせる。
	 */
	void Jump()
	{
		isJump = true;
		isOnGround = false;
	}
	/*!
	 * @brief	ジャンプ中か判定
	 */
	bool IsJump() const
	{
		return isJump;
	}
	/*!
	* @brief	地面上にいるか判定。
	*/
	bool IsOnGround() const
	{
		return isOnGround;
	}
	/*!
	* @brief	ブロックと頭が当たったか判定。
	*/
	bool IsCeiling() const
	{
		return isCeiling;
	}
	/*!
	* @brief	ブロックと頭が当たったか判定。
	*/
	bool IsKabe() const
	{
		return isKabe;
	}
	
	/*!
	* @brief	コライダーを取得。
	*/
	CapsuleCollider* GetCollider()
	{
		return &collider;
	}
	/*!
	* @brief	重力を取得。
	*/
	void SetGravity(float gravity)
	{
		this->gravity = gravity;
	}
	/*!
	* @brief	剛体を取得。
	*/
	RigidBody* GetRigidBody()
	{
		return &rigidBody;
	}
	/*!
	* @brief	剛体を物理エンジンから削除。。
	*/
	void RemoveRigidBoby();
	//<!どのオブジェクトと当たったか?
	const btCollisionObject* getCollisionObj()
	{
		return hitCollisionObject;
	}
private:
	D3DXVECTOR3 				position = D3DXVECTOR3(0.0f,0.0f,0.0f);	//座標。
	D3DXVECTOR3 				moveSpeed = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//移動速度。
	D3DXVECTOR3					UP = D3DXVECTOR3(0.0f, 1.0f, 0.0f);				//上方向のベクトル
	bool 						isJump = false;				//ジャンプ中？
	bool						isOnGround = true;			//地面の上にいる？
	bool						isCeiling = false;			//ブロックと頭があたった？
	bool						isKabe = false;				//壁と当たった？
	CapsuleCollider				collider;						//コライダー。
	float						radius = 0.0f;
	float						height = 0.0f;
	RigidBody					rigidBody;						//剛体。
	float						gravity = -9.8f;				//重力。
	const btCollisionObject*	hitCollisionObject;//どのコリジョンと当たった？
};