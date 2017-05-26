#pragma once
#include "stdafx.h"
#include "shadow.h"
#include "Physics.h"
#include "Light.h"
#include "ParticleEmitter.h"
class Scene
{
public:
	Scene(){}
	virtual ~Scene()
	{
	}
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	

	Pad* GETPad(){ return &pad; }
	Light* GETlight(){ return &light;}
	ShadowMap* Getshadow(){ return &shadow; }
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physics;
	}
	
protected:
	Pad					pad;
	ShadowMap			shadow;
	CParticleEmitter	particleEmitter;	//パーティクルエミッター
	Light				light;
	PhysicsWorld		physics;
};
