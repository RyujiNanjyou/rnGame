/*!
* @brief	�L�[���́B
*/

#ifndef _TKKEYINPUT_H_ 
#define _TKKEYINPUT_H_ 

#include "Pad.h"
	class CKeyInput{

	public:
		static const int NUM_PAD = 4;	//�p�b�h�̐��B
		enum EnKey {
			enKeyUp,
			enKeyDown,
			enKeyRight,
			enKeyLeft,
			enKeyA,
			enKeyB,
			enKeyNum,
		};
		/*!
		* @brief	�R���X�g���N�^�B
		*/
		CKeyInput();
		/*!
		* @brief	�f�X�g���N�^�B
		*/
		~CKeyInput();
		/*!
		* @brief	�L�[���̍X�V�B
		*/
		void Update();
		/*!
		* @brief	��L�[��������Ă���B
		*/
		bool IsUpPress() const
		{
			return keyPressFlag[enKeyUp];
		}
		/*!
		* @brief	�E�L�[��������Ă���B
		*/
		bool IsRightPress() const
		{
			return keyPressFlag[enKeyRight];
		}
		/*!
		* @brief	���L�[��������Ă���B
		*/
		bool IsLeftPress() const
		{
			return keyPressFlag[enKeyLeft];
		}
		/*!
		* @brief	���L�[��������Ă���B
		*/
		bool IsDownPress() const
		{
			return keyPressFlag[enKeyDown];
		}
		/*!
		* @brief	�L�[�̃v���X����B
		*/
		bool IsPress(EnKey key) const
		{
			return keyPressFlag[key];
		}
		/*!
		* @brief	�L�[�̃g���K�[����B
		*/
		bool IsTrgger(EnKey key) const
		{
			return keyTrigerFlag[key];
		}
		/*!
		* @brief	�}�E�X�̍��{�^���������ꂽ�Ƃ��̏����B
		*/
		void OnMouseLButtonUp(int x, int y)
		{
			mousePositionX = x;
			mousePositionY = y;
			isMouseUp[1] = true;
		}
		/*!
		* @brief	�}�E�X�̍��{�^���������ꂽ�Ƃ�������B
		*/
		bool IsMouseLButtonUp() const
		{
			return isMouseUp[0];
		}
		/*!
		* @brief	�}�E�X��X���W���擾�B
		*/
		int GetMousePositionX() const
		{
			return mousePositionX;
		}
		/*!
		* @brief	�}�E�X��Y���W���擾�B
		*/
		int GetMousePositionY() const
		{
			return mousePositionY;
		}
		/*!
		* @brief	�Q�[���p�b�h���擾�B
		*/
		const Pad& GetPad(int padNo) const
		{
			//TK_ASSERT(padNo < NUM_PAD, "padNo is invalid");
			return pad[padNo];
		}
	private:
		bool	keyPressFlag[enKeyNum];
		bool	keyTrigerFlag[enKeyNum];
		bool	isMouseUp[2];
		int		mousePositionX;
		int		mousePositionY;
		Pad		pad[NUM_PAD];		//!<�p�b�h�B
	};

#endif //_TKKEYINPUT_H_ 