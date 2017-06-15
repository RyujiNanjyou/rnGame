#pragma once
#include "stdafx.h"
#include "shadow.h"
#include "Physics.h"
#include "Light.h"
#include "ParticleEmitter.h"

class Scene
{
public:
	/*!
	* @brief	�R���X�g���N�^�B
	*/
	Scene(){}
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	virtual ~Scene()
	{
	}
	/*!
	* @brief	�������B
	*/
	virtual void Init() = 0;
	/*!
	* @brief	�X�V�B
	*/
	virtual void Update() = 0;
	/*!
	* @brief	�`��B
	*/
	virtual void Render() = 0;
	
	/*!
	* @brief	�p�b�h�̎擾�B
	*/
	Pad* GETPad(){ return &pad; }
	/*!
	* @brief	���C�g�̎擾�B
	*/
	Light* GETlight(){ return &light;}
	/*!
	* @brief	�e�̎擾�B
	*/
	ShadowMap* Getshadow(){ return &shadow; }
	/*!
	* @brief	�������[���h�̎擾�B
	*/
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physics;
	}
	
protected:
	Pad					pad;//�Q�[���p�b�h
	ShadowMap			shadow;//�e
	CParticleEmitter	particleEmitter;	//�p�[�e�B�N���G�~�b�^�[
	Light				light;//���C�g
	PhysicsWorld		physics;//�������[���h
};
