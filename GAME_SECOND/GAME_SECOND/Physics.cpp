#include "stdafx.h"
#include "RigidBody.h"
#include "Physics.h"
PhysicsWorld*	physicsworld = NULL;

	PhysicsWorld::PhysicsWorld()
	{
		collisionConfig = NULL;
		collisionDispatcher = NULL;
		overlappingPairCache = NULL;
		constraintSolver = NULL;
		dynamicWorld = NULL;
	}


	PhysicsWorld::~PhysicsWorld()
	{
		Release();
	}
	void PhysicsWorld::Release()
	{
		delete dynamicWorld;
		delete constraintSolver;
		delete overlappingPairCache;
		delete collisionDispatcher;
		delete collisionConfig;
		dynamicWorld = NULL;
		constraintSolver = NULL;
		overlappingPairCache = NULL;
		collisionDispatcher = NULL;
		collisionConfig = NULL;
	}
	void PhysicsWorld::Init()
	{
		//物理エンジンを初期化。
		///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
		collisionConfig = new btDefaultCollisionConfiguration();

		///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
		collisionDispatcher = new	btCollisionDispatcher(collisionConfig);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		overlappingPairCache = new btDbvtBroadphase();

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		constraintSolver = new btSequentialImpulseConstraintSolver;

		dynamicWorld = new btDiscreteDynamicsWorld(
			collisionDispatcher,
			overlappingPairCache,
			constraintSolver,
			collisionConfig
			);

		dynamicWorld->setGravity(btVector3(0, -10, 0));
	}
	void PhysicsWorld::Update()
	{
		if (dynamicWorld != NULL){ dynamicWorld->stepSimulation(1.0f / 60.0f); }
		
	}
	void PhysicsWorld::AddRigidBody(RigidBody* rb)
	{
		if (dynamicWorld != NULL){
			dynamicWorld->addRigidBody(rb->GetBody());
		}
	}
	void PhysicsWorld::RemoveRigidBody(RigidBody* rb)
	{
		if (dynamicWorld != NULL){
			dynamicWorld->removeRigidBody(rb->GetBody());
		}
	}
