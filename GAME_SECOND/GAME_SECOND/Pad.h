/*!
*@brief	�p�b�h
*/
#pragma once
#include <XInput.h> // XInput API
	/*!
	*@brief	���z�{�^����`�B
	*/
enum EnButton{
	enButtonUp,		//!<��B
	enButtonDown,		//!<���B
	enButtonLeft,		//!<���B
	enButtonRight,		//!<�E�B
	enButtonA,			//!<A�{�^���B
	enButtonB,			//!<B�{�^���B
	enButtonX,			//!<X�{�^���B
	enButtonY,			//!<Y�{�^���B
	enButtonSelect,	//!<�Z���N�g�{�^���B
	enButtonStart,		//!<�X�^�[�g�{�^���B
	enButtonRB1,		//!<RB1�{�^���B
	enButtonRB2,		//!<RB2�{�^���B
	enButtonRB3,		//!<RB3�{�^���B
	enButtonLB1,		//!<LB1�{�^���B
	enButtonLB2,		//!<LB2�{�^���B
	enButtonLB3,		//!<LB3�{�^���B
	enButtonNum,	//!<�{�^���̐��B
};
	/*!
	*@brief	�p�b�h
	*/
class Pad{
public:
	/*!
	*@brief	�p�b�h�X�e�[�g�B
	*/
	struct PAD_STATE
	{
		XINPUT_STATE state;
		bool bConnected;
	};
	/*!
	*@brief	�R���X�g���N�^�B
	*/
	Pad();
	/*!
	*@brief	�f�X�g���N�^�B
	*/
	~Pad();
	/*!
	*@brief	�������B
	*@param[in]	padNo	�p�b�h�ԍ��B
	*/
	void Init(int padNo)
	{
		padNo = padNo;
	}
	/*!
	*@brief	�X�V�B
	*/
	void Update();
	/*!
	*@brief	�{�^���̃g���K�[����B
	*@return	true���Ԃ��Ă�����g���K�[���́B
	*/
	bool IsTrigger(EnButton button) const
	{
		//TK_ASSERT(button < enButtonNum, "button is invalid");
		return trigger[button] != 0;
	}
	/*!
	*@brief	�{�^����������Ă��邩����B
	*@return	true���Ԃ��Ă����牟����Ă���B
	*/
	bool IsPress(EnButton button) const
	{
		//TK_ASSERT(button < enButtonNum, "button is invalid");
		return press[button] != 0;
	}
	/*!
	*@brief	���X�e�B�b�N��X���̓��͗ʂ��擾�B
	*@return	-1.0�`1.0�̐��K�����ꂽ�l��Ԃ��B
	*/
	float GetLStickXF() const
	{
		return lStickX;
	}
	/*!
	*@brief	���X�e�B�b�N��Y���̓��͗ʂ��擾�B
	*@return	-1.0�`1.0�̐��K�����ꂽ�l��Ԃ��B
	*/
	float GetLStickYF() const
	{
		return lStickY;
	}
	/*!
	*@brief	�E�X�e�B�b�N��X���̓��͗ʂ��擾�B
	*@return	-1.0�`1.0�̐��K�����ꂽ�l��Ԃ��B
	*/
	float GetRStickXF() const
	{
		return rStickX;
	}
	/*!
	*@brief	�E�X�e�B�b�N��Y���̓��͗ʂ��擾�B
	*@return	-1.0�`1.0�̐��K�����ꂽ�l��Ԃ��B
	*/
	float GetRStickYF() const
	{
		return rStickY;
	}
	bool Getf(){ return padflag; }
	void Setf(bool f){ padflag = f; }
private:
	PAD_STATE state;	//!<�p�b�h�X�e�[�g�B
	int padNo;		//!<�p�b�h�ԍ��B
	int trigger[enButtonNum];	//!<�g���K�[���͂̃t���O�B
	int press[enButtonNum];	//!<press���͂̃t���O�B
	float lStickX;			//!<���X�e�B�b�N��X���̓��͗ʁB
	float lStickY;			//!<���X�e�B�b�N��Y���̓��͗ʁB
	float rStickX;			//!<�E�X�e�B�b�N��X���̓��͗ʁB
	float rStickY;			//!<�E�X�e�B�b�N��Y���̓��͗ʁB
	bool padflag;
};