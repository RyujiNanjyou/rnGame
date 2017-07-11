#pragma once
#include "GameObject.h"
#include "CharacterController.h"
#include "PlayerStateIdol.h"
#include "PlayerStateRun.h"
#include "PlayerStateDamage.h"
#include "PlayerStateDead.h"
#include "LockOn2D.h"
#include "Enemy.h"
/*!
* @brief	�v���C���[�B
*/
class Player : public GameObject
{
public:
	//�A�j���[�V������ԁB
	enum  PlayerAnimNo
	{
		INVALID = -1,
		IDOL = 0, //�ҋ@
		WALK, //����
		RUN, // ����
		JUMP, //�W�����v
	};
	//�v���C���[�̏�ԁB
	enum NowState
	{
		STATE_RUN, //�����Ă���B
		STATE_IDOL, //�ҋ@���Ă���B
		STATE_DAMAGE, //�_���[�W�󂯂Ă���B
		STATE_DEAD //���S�B
	};
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Player();
	/*!
	*@brief	�f�X�g���N�^
	*/
	~Player();
	/*!
	*@brief	������
	*@param[in] pd3dDevice	�f�o�C�X
	*@param[in] Name		�t�@�C����
	*/
	void Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* Name) override;
	/*!
	*@brief	�X�V
	*/
	bool Update() override;
	/*!
	*@brief	�`��
	*@param[in] viwe		�r���[�s��
	*@param[in] proj		�v���W�F�N�V�����s��
	*@param[in] ShadowFlag	�e�𗎂Ƃ����̃t���O
	*/
	void Render(const D3DXMATRIX& viwe, const D3DXMATRIX& proj, bool ShadowFlag, bool isZPrepass) override;
	/*!
	*@brief	��Ԃ̍X�V
	*/
	void UpdateState();
	/*!
	* @brief	�A�j���[�V�����Đ��B
	*/
	void PlayAnimation(PlayerAnimNo animNo, float interpolate);
	/*!
	*@brief	�A�j���[�V�����B
	*/
	void Animation();
	/*!
	*@brief	��ԑJ�ځB
	*@param[in] nexstate	�J�ڂ����������
	*/
	void ChangeState(NowState nexstate);
	/*!
	*@brief	�_���[�W�����B
	*/
	void Damage();
	/*!
	*@brief	�G�ւ̃��b�N�I���B
	*/
	bool LockOnEnemy();
	/*!
	*@brief	�^�[�Q�b�g�B
	*/
	void Target();
	/*!
	*@brief	�e�̌������B
	*/
	void ShotPlayer( D3DXVECTOR3& pos, const D3DXVECTOR3& forward);
	/*!
	*@brief	�����̎擾�B
	*/
	const D3DXVECTOR3&	Getforward() const { return forward; }
	/*!
	*@brief	�q�b�g�|�C���g�̎擾�B
	*/
	int Gethp()const{ return hp; }
	/*!
	*@brief	�ő�q�b�g�|�C���g�̎擾�B
	*/
	const int Getmaxhp()const{ return maxhp; }
	/*!
	*@brief	�_���[�W�t���O�̎擾�B
	*/
	bool GetisDamage()const { return isDamage; }
	/*!
	*@brief	���̏�Ԃ̎擾�B
	*/
	NowState GetNowS()const { return state; }

private:
	friend class	PlayerStateRun;
	friend class	PlayerStateIdol;
	friend class	PlayerStateDamage;
	friend class	PlayerStateDead;
	
	NowState						state;											//���
	NowState						lastFrameState;									//�Ō�̃t���[�����
	PlayerState*					currentState = NULL;							//���ݏ��
	PlayerStateIdol					idolstate;										//�ҋ@���
	PlayerStateRun					runstate;										//������
	PlayerStateDamage				damagestate;									//�_���[�W���
	PlayerStateDead					deadstate;										//���S���
	D3DXVECTOR3						forward;										//����
	int								hp = 50;										//�q�b�g�|�C���g
	const int						maxhp = 50;										//�ő�q�b�g�|�C���g
	float							radius = 0.4f;									//����
	float							height = 0.7f;									//�c��
	bool							isApplyDamageTrigger = false;					//�_���[�W�K�p�t���O
	bool							isApplyDeadTrigger = false;						//���S�K�p�t���O
	bool							islockOn = false;								//���b�N�I���t���O
	bool							isDamage =  false;								//�_���[�W�t���O
	Enemy*							lockOnEnemy = NULL;								//���b�N�I���ł���G
	LPDIRECT3DTEXTURE9				normalMap = skinmodel.GetNormal();				//<!�m�[�}���}�b�v�B
	LPDIRECT3DTEXTURE9				specularMap = skinmodel.GetSpec();				//<!�X�y�L�����}�b�v�B
	LPDIRECT3DTEXTURE9				darkTex;
	int								intervalTime = 0;								//�N�[���^�C��
	int								shotintervalTime = 0;							//�U���N�[���^�C��
	int								damageTime = 0;									//�_���[�W�N�[���^�C��
	bool							renderflag = false;								//�`��t���O
	std::unique_ptr<SoundSource>	Attackse;										//�U���T�E���h
	std::unique_ptr<SoundSource>	Jumpse;											//�W�����v�T�E���h
	
};

