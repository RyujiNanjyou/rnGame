/*!
* @brief	キャラクタのコリジョンコントロール。
*/
#include "stdafx.h"
#include "tkEnginePreCompile.h"
#include "CharacterController.h"
#include "CollisionAttr.h"
#include "GameScene.h"
		//衝突したときに呼ばれる関数オブジェクト(地面用)
		struct SweepResultGround : public btCollisionWorld::ConvexResultCallback
		{
			const btCollisionObject* hitCollisionObject = NULL;		//衝突したコリジョンオブジェクト
			bool isHit = false;									//衝突フラグ。
			D3DXVECTOR3 hitPos = D3DXVECTOR3(0.0f, -FLT_MAX, 0.0f);	//衝突点。
			D3DXVECTOR3 startPos = D3DXVECTOR3(0.0f,0.0f,0.0f);					//レイの始点。
			D3DXVECTOR3 hitNormal = D3DXVECTOR3(0.0f,0.0f,0.0f);				//衝突点の法線。
			btCollisionObject* me = nullptr;					//自分自身。自分自身との衝突を除外するためのメンバ。
			float dist = FLT_MAX;								//衝突点までの距離。一番近い衝突点を求めるため。FLT_MAXは単精度の浮動小数点が取りうる最大の値。

																//衝突したときに呼ばれるコールバック関数。
			virtual	btScalar	addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
			{
				if (convexResult.m_hitCollisionObject == me
					|| convexResult.m_hitCollisionObject->getUserIndex() == enCollisionAttr_Character
					) {
					//自分に衝突した。or キャラクタ属性のコリジョンと衝突した。
					return 0.0f;
				}
				//衝突点の法線を引っ張ってくる。
				D3DXVECTOR3 hitNormalTmp = *(D3DXVECTOR3*)&convexResult.m_hitNormalLocal;
				//上方向と法線のなす角度を求める。
				float angle = D3DXVec3Dot(&hitNormalTmp, &D3DXVECTOR3(0.0f, 1.0f, 0.0f));
				angle = fabsf(acosf(angle));
				if (angle < PI * 0.3f		//地面の傾斜が54度より小さいので地面とみなす。
					|| convexResult.m_hitCollisionObject->getUserIndex() == enCollisionAttr_Ground //もしくはコリジョン属性が地面と指定されている。
					) {
					//衝突している。
					isHit = true;
					D3DXVECTOR3 hitPosTmp = *(D3DXVECTOR3*)&convexResult.m_hitPointLocal;
					//衝突点の距離を求める。。
					D3DXVECTOR3 vDist;
					vDist = hitPosTmp - startPos;
					float distTmp = D3DXVec3Length(&vDist);
					if (dist > distTmp) {
						//この衝突点の方が近いので、最近傍の衝突点を更新する。
						hitPos = hitPosTmp;
						hitNormal = *(D3DXVECTOR3*)&convexResult.m_hitNormalLocal;
						hitCollisionObject = convexResult.m_hitCollisionObject;
						dist = distTmp;
					}
				}
				return 0.0f;
			}
		};
		//衝突したときに呼ばれる関数オブジェクト(壁用)
		struct SweepResultWall : public btCollisionWorld::ConvexResultCallback
		{
			const btCollisionObject* hitCollisionObject = NULL;	//衝突したコリジョンオブジェクト
			bool isHit = false;						//衝突フラグ。
			D3DXVECTOR3 hitPos = D3DXVECTOR3(0.0f,0.0f,0.0f);		//衝突点。
			D3DXVECTOR3 startPos = D3DXVECTOR3(0.0f,0.0f,0.0f);		//レイの始点。
			float dist = FLT_MAX;					//衝突点までの距離。一番近い衝突点を求めるため。FLT_MAXは単精度の浮動小数点が取りうる最大の値。
			D3DXVECTOR3 hitNormal = D3DXVECTOR3(0.0f,0.0f,0.0f);	//衝突点の法線。
			btCollisionObject* me = nullptr;		//自分自身。自分自身との衝突を除外するためのメンバ。
													//衝突したときに呼ばれるコールバック関数。
			virtual	btScalar	addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
			{
				if (convexResult.m_hitCollisionObject == me) {
					//自分に衝突した。or 地面に衝突した。
					return 0.0f;
				}
				//衝突点の法線を引っ張ってくる。
				D3DXVECTOR3 hitNormalTmp;
				hitNormalTmp = (D3DXVECTOR3)convexResult.m_hitNormalLocal;
				//上方向と衝突点の法線のなす角度を求める。
				float angle = fabsf(acosf(D3DXVec3Dot(&hitNormalTmp, &D3DXVECTOR3(0.0f, 1.0f, 0.0f))));
				if (angle > PI * 0.3f		//地面の傾斜が54度以上なので壁とみなす。
					|| convexResult.m_hitCollisionObject->getUserIndex() == enCollisionAttr_Character	//もしくはコリジョン属性がキャラクタなので壁とみなす。
					) {
					isHit = true;
					D3DXVECTOR3 hitPosTmp;
					hitPosTmp = D3DXVECTOR3(convexResult.m_hitPointLocal);
					//交点との距離を調べる。
					D3DXVECTOR3 vDist;
					vDist = hitPosTmp - startPos;
					vDist.y = 0.0f;
					float distTmp = D3DXVec3Length(&vDist);
					if (distTmp < dist) {
						//この衝突点の方が近いので、最近傍の衝突点を更新する。
						hitPos = hitPosTmp;
						dist = distTmp;
						hitNormal = hitNormalTmp;
						hitCollisionObject = convexResult.m_hitCollisionObject;
					}
				}
				return 0.0f;
			}
			
		};
		//衝突したときに呼ばれる関数オブジェクト(天井用)
		struct SweepResultCeiling : public btCollisionWorld::ConvexResultCallback
		{
			const btCollisionObject* hitCollisionObject = NULL;	//衝突したコリジョンオブジェク
			bool isHit = false;									//衝突フラグ。
			D3DXVECTOR3 hitPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//衝突点。
			D3DXVECTOR3 startPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);					//レイの始点。
			D3DXVECTOR3 hitNormal = D3DXVECTOR3(0.0f, 0.0f, 0.0f);				//衝突点の法線。
			btCollisionObject* me = nullptr;					//自分自身。自分自身との衝突を除外するためのメンバ。
			float dist = FLT_MAX;								//衝突点までの距離。一番近い衝突点を求めるため。FLT_MAXは単精度の浮動小数点が取りうる最大の値。

			//衝突したときに呼ばれるコールバック関数。
			virtual	btScalar	addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
			{
				
				//衝突点の法線を引っ張ってくる。
				D3DXVECTOR3 hitNormalTmp = *(D3DXVECTOR3*)&convexResult.m_hitNormalLocal;

				D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);
				float d = D3DXVec3Dot(&hitNormalTmp, &Up);
				if (d > 0.0f) {
					//当たってない。
					return 0.0f;
				}
				//上方向と法線のなす角度を求める。
				float angle = D3DXVec3Dot(&hitNormalTmp, &D3DXVECTOR3(0.0f, -1.0f, 0.0f));
				angle = fabsf(acosf(angle));
				if (angle > 0.9f)		//壁判定
				{
					return 0.0f;
				}
				//衝突している。
				isHit = true;
				D3DXVECTOR3 hitPosTmp = *(D3DXVECTOR3*)&convexResult.m_hitPointLocal;
				//衝突点の距離を求める。。
				D3DXVECTOR3 vDist;
				vDist = hitPosTmp - startPos;
				float distTmp = D3DXVec3Length(&vDist);
				if (dist > distTmp) {
					//この衝突点の方が近いので、最近傍の衝突点を更新する。
					hitPos = hitPosTmp;
					hitNormal = *(D3DXVECTOR3*)&convexResult.m_hitNormalLocal;
					hitCollisionObject = convexResult.m_hitCollisionObject;
					dist = distTmp;
				}
				return 0.0f;
			}
			//virtual	btScalar	addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
			//{
			//	if (convexResult.m_hitCollisionObject->getUserIndex() != -1) {
			//		//無視。
			//		return 0.0f;
			//	}
			//	D3DXVECTOR3 hitPointNormal;

			//	hitPointNormal.x = convexResult.m_hitNormalLocal.x();
			//	hitPointNormal.y = convexResult.m_hitNormalLocal.y();
			//	hitPointNormal.z = convexResult.m_hitNormalLocal.z();

			//	D3DXVECTOR3 Up(0.0f, 1.0f, 0.0f);

			//	float d = D3DXVec3Dot(&hitPointNormal, &Up);
			//	if (d > 0.0f) {
			//		//当たってない。
			//		return 0.0f;
			//	}
			//	if (acosf(d) < PI * 0.2) {
			//		//ホントは地面かどうかとかの属性を見るのがベストなんだけど、今回は角度で。
			//		return 0.0f;
			//	}
			//	isHit = true;

			//	hitPos.x = convexResult.m_hitPointLocal.x();
			//	hitPos.y = convexResult.m_hitPointLocal.y();
			//	hitPos.z = convexResult.m_hitPointLocal.z();
			//	hitCollisionObject = convexResult.m_hitCollisionObject;
			//	return 0.0f;

			//}
		};


		void CharacterController::Init(float radius, float height, const D3DXVECTOR3& position)
	{
		this->position = position;
		//コリジョン作成。
		this->radius = radius;
		this->height = height;							
		collider.Create(radius, height);			//コライダークリエイト
		
		//剛体を初期化。
		RigidBodyInfo rbInfo;
		rbInfo.collider = &collider;
		rbInfo.mass = 0.0f;
		rigidBody.Create(rbInfo);
		btTransform& trans = rigidBody.GetBody()->getWorldTransform();
		//剛体の位置を更新。
		trans.setOrigin(btVector3(position.x, position.y, position.z));
		//@todo 未対応。trans.setRotation(btQuaternion(rotation.x, rotation.y, rotation.z));
		rigidBody.GetBody()->setUserIndex(enCollisionAttr_Character);
		rigidBody.GetBody()->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);
		//game->GetPhysicsWorld()->AddRigidBody(&m_rigidBody);

	}
		void CharacterController::Execute()
	{
		//速度に重力加速度を加える。
		moveSpeed.y += gravity * 1.0f / 60.0f;
		//次の移動先となる座標を計算する。
		D3DXVECTOR3 nextPosition = position;
		//速度からこのフレームでの移動量を求める。オイラー積分。
		D3DXVECTOR3 addPos = moveSpeed;
		addPos *= 1.0f / 60.0f;
		nextPosition += addPos;
		D3DXVECTOR3 originalXZDir = addPos;
		originalXZDir.y = 0.0f;
		D3DXVec3Normalize(&originalXZDir, &originalXZDir);
		//XZ平面での衝突検出と衝突解決を行う。
		{
			isKabe = false;
			int loopCount = 0;
			while (true) {
				//現在の座標から次の移動先へ向かうベクトルを求める。
				D3DXVECTOR3 addPos;
				addPos = nextPosition - position;
				D3DXVECTOR3 addPosXZ = addPos;
				addPosXZ.y = 0.0f;
				if (D3DXVec3Length(&addPosXZ) < FLT_EPSILON) {
					//XZ平面で動きがないので調べる必要なし。
					//FLT_EPSILONは1より大きい、最小の値との差分を表す定数。
					//とても小さい値のことです。
					break;
				}
				//カプセルコライダーの中心座標 + 0.2の座標をposTmpに求める。
				D3DXVECTOR3 posTmp = position;
				posTmp.y += height * 0.5f + radius + 0.2f;
				//レイを作成。
				btTransform start, end;
				start.setIdentity();
				end.setIdentity();
				//始点はカプセルコライダーの中心座標 + 0.2の座標をposTmpに求める。
				start.setOrigin(btVector3(posTmp.x, posTmp.y, posTmp.z));
				//終点は次の移動先。XZ平面での衝突を調べるので、yはposTmp.yを設定する。
				end.setOrigin(btVector3(nextPosition.x, posTmp.y, nextPosition.z));

				SweepResultWall callback;
				callback.me = rigidBody.GetBody();
				callback.startPos = posTmp;
				//衝突検出。
				game->GetPhysicsWorld()->ConvexSweepTest((const btConvexShape*)collider.GetBody(), start, end, callback);
				if (callback.isHit) {
					//当たった。
					//壁。
					isKabe = true;
					hitCollisionObject = callback.hitCollisionObject;//壁のコリジョンオブジェクトと当たった。
					D3DXVECTOR3 vT0, vT1;
					//XZ平面上での移動後の座標をvT0に、交点の座標をvT1に設定する。
					vT0 = D3DXVECTOR3(nextPosition.x, 0.0f, nextPosition.z);
					vT1 = D3DXVECTOR3(callback.hitPos.x, 0.0f, callback.hitPos.z);
					//めり込みが発生している移動ベクトルを求める。
					D3DXVECTOR3 vMerikomi;
					vMerikomi = vT0 - vT1;
					//XZ平面での衝突した壁の法線を求める。。
					D3DXVECTOR3 hitNormalXZ = callback.hitNormal;
					hitNormalXZ.y = 0.0f;
					D3DXVec3Normalize(&hitNormalXZ, &hitNormalXZ);
					//めり込みベクトルを壁の法線に射影する。
					float fT0 = D3DXVec3Dot(&hitNormalXZ, &vMerikomi);
					//押し戻し返すベクトルを求める。
					//押し返すベクトルは壁の法線に射影されためり込みベクトル+半径。
					D3DXVECTOR3 vOffset;
					vOffset = hitNormalXZ;
					vOffset *= (-fT0 + radius);
					nextPosition += vOffset;
					D3DXVECTOR3 currentDir;
					currentDir = nextPosition - position;
					currentDir.y = 0.0f;
					D3DXVec3Normalize(&currentDir, &currentDir);
					if (D3DXVec3Dot(&currentDir, &originalXZDir) < 0.0f) {
						//角に入った時のキャラクタの振動を防止するために、
						//移動先が逆向きになったら移動をキャンセルする。
						nextPosition.x = position.x;
						nextPosition.z = position.z;
						break;
					}
				}
				else {
					//どことも当たらないので終わり。
					break;
				}
				loopCount++;
				if (loopCount == 5) {
					break;
				}
			}
		}
		//XZの移動は確定。
		position.x = nextPosition.x;
		position.z = nextPosition.z;

		//上方向を調べる。
#if 1
		isCeiling = false;
		{
			D3DXVECTOR3 addPos(0.0f, 0.0f, 0.0f);
			addPos = nextPosition - position;
			btTransform start, end;
			start.setIdentity();
			end.setIdentity();
			btVector3 btStart = btVector3(position.x, position.y, position.z);
			start.setOrigin(btStart);

			SweepResultCeiling callback;
			if (addPos.y > 0.0f){
				if (fabsf(addPos.y) > 0.0001f) {
					end.setOrigin(btVector3(nextPosition.x, nextPosition.y, nextPosition.z));
					callback.me = rigidBody.GetBody();
					callback.startPos = D3DXVECTOR3(btStart);
					//衝突検出。
					game->GetPhysicsWorld()->ConvexSweepTest((const btConvexShape*)collider.GetBody(), start, end, callback);
				}
				if (callback.isHit) {
					//当たった。
					//天井。
					isCeiling = true;
					hitCollisionObject = callback.hitCollisionObject;
					moveSpeed.y = 0.0f;
					nextPosition.y = callback.hitPos.y - height;
				}
			}
		}
#endif

		//下方向を調べる。
		{
			D3DXVECTOR3 addPos;
			addPos = nextPosition - position;
			position = nextPosition;	//移動の仮確定。
			
			if (addPos.y < 0.0f){
				//レイを作成する。
				btTransform start, end;
				start.setIdentity();
				end.setIdentity();
				//始点はカプセルコライダーの中心。
				start.setOrigin(btVector3(position.x, position.y + height * 0.5f + radius, position.z));
				//終点は地面上にいない場合は1m下を見る。
				//地面上にいなくてジャンプで上昇中の場合は上昇量の0.01倍下を見る。
				//地面上にいなくて降下中の場合はそのまま落下先を調べる。
				D3DXVECTOR3 endPos;
				endPos = D3DXVECTOR3(start.getOrigin());
				endPos.y += addPos.y;
				end.setOrigin(btVector3(endPos.x, endPos.y, endPos.z));
				SweepResultGround callback;
				callback.me = rigidBody.GetBody();
				callback.startPos = D3DXVECTOR3(start.getOrigin());
				if (fabsf(start.getOrigin().y() - endPos.y) > 0.0f) {
					//衝突検出。
					game->GetPhysicsWorld()->ConvexSweepTest((const btConvexShape*)collider.GetBody(), start, end, callback);
					
					if (start.getOrigin().y() - end.getOrigin().y() > 0.001f)
					{
						if (callback.isHit) {
							//当たった。
							hitCollisionObject = callback.hitCollisionObject;	//地面のコリジョンオブジェクトと当たった。
							moveSpeed.y = 0.0f;
							isJump = false;
							isOnGround = true;
							nextPosition.y = callback.hitPos.y;
						}
						else {
							//地面上にいない。
							isOnGround = false;
							//m_isJump = true;
						}
					}
					
				}
			}
		}

		//移動確定。
		position = nextPosition;
		btRigidBody* btBody = rigidBody.GetBody();
		//剛体を動かす。
		btBody->setActivationState(DISABLE_DEACTIVATION);
		btTransform& trans = btBody->getWorldTransform();
		//剛体の位置を更新。
		trans.setOrigin(btVector3(position.x, position.y, position.z));
		//@todo 未対応。 trans.setRotation(btQuaternion(rotation.x, rotation.y, rotation.z));
	}
	/*!
	* @brief	死亡したことを通知。
	*/
	void CharacterController::RemoveRigidBoby()
	{
		game->GetPhysicsWorld()->RemoveRigidBody(&rigidBody);
	}