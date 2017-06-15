#pragma once
/*!
*@brief	�J�����B
*/
class Camera
{
public:
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Camera();
	/*!
	*@brief	�f�X�g���N�^
	*/
	~Camera();
	/*!
	*@brief	�A�X�y�N�g���ݒ�B
	*/
	void SetAspect(float _aspect)
	{
		aspect = _aspect;
	}
	/*!
	*@brief	�A�X�y�N�g����擾�B
	*/
	float GetAspect() const
	{
		return aspect;
	}
	/*!
	*@brief	�t�@�[��ݒ�B
	*/
	void SetFar(float _far)
	{
		Far = _far;
	}
	/*!
	*@brief	�j�A���擾�B
	*/
	float GetNear() const
	{
		return Near;
	}
	/*!
	*@brief	�t�@�[���擾�B
	*/
	float GetFar() const
	{
		return Far;
	}
	/*!
	*@brief	�j�A��ݒ�B
	*/
	void SetNear(float _near)
	{
		Near = _near;
	}
	/*!
	*@brief	���_��ݒ�B
	*/
	void SetEyePt(D3DXVECTOR3 pt)
	{
		vEyePt = pt;
	}
	/*!
	*@brief	���_���擾�B
	*/
	D3DXVECTOR3 GetEyePt() const
	{
		return vEyePt;
	}
	/*!
	*@brief	�����_��ݒ�B
	*/
	void SetLookatPt(D3DXVECTOR3 pt)
	{
		vLookatPt = pt;
	}
	/*!
	*@brief	�����_�̎擾�B
	*/

	D3DXVECTOR3 GetLookatPt() const
	{
		return vLookatPt;
	}
	/*!
	*@brief	������̐ݒ�B
	*/
	void SetUpVec(D3DXVECTOR3 up)
	{
		vUpVec = up;
	}
	/*!
	*@brief	������̎擾�B
	*/
	D3DXVECTOR3 GetUpVec() const
	{
		return vUpVec;
	}
	/*!
	*@brief	�r���[�s��̐ݒ�B
	*/
	void SetViewMatrix(D3DXMATRIX mView)
	{
		viewMatrix = mView;
	}
	/*!
	*@brief	�r���[�s��̎擾�B
	*/
	D3DXMATRIX GetViewMatrix() const
	{
		return viewMatrix;
	}
	/*!
	*@brief	�v���W�F�N�V�����s��̐ݒ�B
	*/
	void SetProjectionMatrix(D3DXMATRIX mProj)
	{
		projectionMatrix = mProj;
	}
	/*!
	*@brief	�v���W�F�N�V�����s��̎擾�B
	*/
	D3DXMATRIX GetProjectionMatrix() const
	{
		return projectionMatrix;
	}
	/*!
	*@brief	�J�����̍X�V�����B
	*/
	void Update();
	/*!
	*@brief	�J�����̏������B
	*/
	void Init();
	
	/*!
	*@brief	���[���h���W����X�N���[�����W���v�Z�B
	*@param[in]�@screenPos�@�X�N���[�����W
	*@param[in]�@worldPos	���[���h���W
	*/
	void CalcScreenPositionFromWorldPosition(D3DXVECTOR2& screenPos, const D3DXVECTOR3& worldPos) const;
	
private:
	D3DXMATRIX				viewMatrix;			//!<�r���[�s��B�J�����s��Ƃ������B
	D3DXMATRIX				projectionMatrix;	//!<�v���W�F�N�V�����s��B�r���[��Ԃ���ˉe��Ԃɕϊ�����s��B
	D3DXMATRIX				viewproj;
	D3DXVECTOR3				vEyePt;				//!<�J�����N���X����邽�߂̃q���g�B�J�����̎��_�B���̕ӂ�̓����o�ϐ��ɕύX����B
	D3DXVECTOR3				vLookatPt;			//!<�J�����N���X����邽�߂̃q���g�B�J�����̒����_�B�ǂ������Ă��邩�Ƃ������B���̕ӂ�̓����o�ϐ��ɕύX����B
	D3DXVECTOR3				vUpVec;				//!<�J�����N���X����邽�߂̃q���g�B�J�����̏�����B��{�I��Y�����ł��܂�Ȃ��B��{�I�ɂ́E�E�E�B���̕ӂ�̓����o�ϐ��ɕύX����B
	float					Far;				//!<�����ʁB
	float					Near;				//!<�ߕ��ʁB
	float					aspect;				//!<�A�X�y�N�g��
};