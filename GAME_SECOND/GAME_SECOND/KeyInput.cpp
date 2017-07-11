/*!
* @brief	�L�[����
*/
#include "stdafx.h"
#include "tkEnginePreCompile.h"
#include "KeyInput.h"


	/*!
	* @brief	�R���X�g���N�^�B
	*/
	CKeyInput::CKeyInput()
	{
		memset(keyPressFlag, 0, sizeof(keyPressFlag));
		memset(keyTrigerFlag, 0, sizeof(keyTrigerFlag));
		mousePositionX = 0;
		mousePositionY = 0;
		isMouseUp[0] = false;
		isMouseUp[1] = false;
		int padNo = 0;
		for (Pad& pad : pad) {
			pad.Init(padNo);
			padNo++;
		}
	}
	/*!
	* @brief	�f�X�g���N�^�B
	*/
	CKeyInput::~CKeyInput()
	{
	}
	/*!
	* @brief	�L�[���̍X�V�B
	*/
	void CKeyInput::Update()
	{
		memset(keyTrigerFlag, 0, sizeof(keyTrigerFlag));
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			keyPressFlag[enKeyUp] = true;
		}
		else {
			keyPressFlag[enKeyUp] = false;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			keyPressFlag[enKeyDown] = true;
		}
		else {
			keyPressFlag[enKeyDown] = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			keyPressFlag[enKeyRight] = true;
		}
		else {
			keyPressFlag[enKeyRight] = false;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			keyPressFlag[enKeyLeft] = true;
		}
		else {
			keyPressFlag[enKeyLeft] = false;
		}
		if ((GetAsyncKeyState('A') & 0x8000) | (GetAsyncKeyState('a') & 0x8000)) {
			if (!keyPressFlag[enKeyA]) {
				keyTrigerFlag[enKeyA] = true;
			}
			keyPressFlag[enKeyA] = true;
		}
		else {
			keyPressFlag[enKeyA] = false;
		}
		if ((GetAsyncKeyState('B') & 0x8000) | (GetAsyncKeyState('b') & 0x8000)) {
			if (!keyPressFlag[enKeyB]) {
				keyTrigerFlag[enKeyB] = true;
			}
			keyPressFlag[enKeyB] = true;
		}
		else {
			keyPressFlag[enKeyB] = false;
		}
		//�o�b�N�o�b�t�@�̓��e���t�����g�o�b�t�@�ɃR�s�[�B
		isMouseUp[0] = isMouseUp[1];
		isMouseUp[1] = false;

		for (Pad& pad : pad) {
			pad.Update();
		}
	}
