#pragma once
#include "GameObject.h"
#include "Sprite.h"
/*!
*@brief	�{�X�B
*/
class Boss : public GameObject
{
public:
	//���
	enum NowBossState
	{
		BossSTATE_RUN,//����
		BossSTATE_IDOL,//�ҋ@
		BossSTATE_DAMAGE,//�_���[�W
		BossSTATE_DEAD,//���S
		BossSTATE_ATTACK//�U��
	};
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Boss();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Boss();
	/*!
	*@brief	�������B
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	�X�V�B
	*/
	bool Update() override;
	/*!
	*@brief	�`��B
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*@param[in] ShadowFlag	�e�𗎂Ƃ����̃t���O
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	�_���[�W�����B
	*/
	void Damage();
	/*!
	*@brief	�U���B
	*/
	void Attackshot();
	/*!
	*@brief	�q�b�g�|�C���g�擾�B
	*/
	int Gethp() const { return hp; }
	/*!
	*@brief	�ő�q�b�g�|�C���g�擾�B
	*/
	int Getmaxhp()const{ return maxhp; }
	/*!
	*@brief	�{�X�̏�Ԃ̎擾�B
	*/
	NowBossState GetBossS() { return nowbossS; }
private:
	NowBossState					nowbossS;					//���
	float							radius = 0.3f;				//����
	float							height = 0.7f;				//�c��
	int								hp = 10;					//�q�b�g�|�C���g
	const int						maxhp = 10;					//�ő�q�b�g�|�C���g
	bool							comp = false;				//�N���A�t���O
	int								intervalTime = 0;			//�N�[���^�C��
	int								intervalDamageTime = 0;		//�_���[�W�N�[���^�C��
	int								renderTime = 0;				//�`��N�[���^�C��
	float							num = 0.0f;					//�^�C�}�[
	const float						deltaTime = 1.0f / 60.0f;	//�f���^�^�C��
	bool							renderflag = false;			//�`��t���O
	std::unique_ptr<SoundSource>	bossAttackse;				//�U���T�E���h
	std::unique_ptr<SoundSource>	deathse;					//���S�T�E���h
};

