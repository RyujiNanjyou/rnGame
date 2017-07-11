/*!
*@brief	パッド。
*/
#include "stdafx.h"
#include "Pad.h"


#define INPUT_DEADZONE  ( 0.24f * FLOAT(0x7FFF) )  // Default to 24% of the +/- 32767 range.   This is a reasonable default value but can be altered if needed.

namespace {
	/*!
	*@brief	仮想ボタンとXBoxコントローラのボタンとの関連付けを表す構造体。
	*@param[in]	padNo	パッド番号。
	*/
	struct VirtualPadToXPad {
		EnButton vButton;		//!<仮想ボタン。
		DWORD	 xButton;		//!<XBoxコントローラのボタン。
	};
	const VirtualPadToXPad vPadToXPadTable[enButtonNum] = {
		{ enButtonUp, XINPUT_GAMEPAD_DPAD_UP },
		{ enButtonDown, XINPUT_GAMEPAD_DPAD_DOWN },
		{ enButtonLeft, XINPUT_GAMEPAD_DPAD_LEFT },
		{ enButtonRight, XINPUT_GAMEPAD_DPAD_RIGHT },
		{ enButtonA, XINPUT_GAMEPAD_A },
		{ enButtonB, XINPUT_GAMEPAD_B },
		{ enButtonY, XINPUT_GAMEPAD_Y },
		{ enButtonX, XINPUT_GAMEPAD_X },
		{ enButtonSelect, XINPUT_GAMEPAD_BACK },
		{ enButtonStart, XINPUT_GAMEPAD_START },
		{ enButtonRB1, XINPUT_GAMEPAD_RIGHT_SHOULDER },
		{ enButtonRB2, 0 },
		{ enButtonRB3, XINPUT_GAMEPAD_RIGHT_THUMB },
		{ enButtonLB1, XINPUT_GAMEPAD_LEFT_SHOULDER },
		{ enButtonLB2, 0 },
		{ enButtonLB3, XINPUT_GAMEPAD_LEFT_THUMB },
	};
	struct VirtualPadToKeyboard {
		EnButton vButton;		//!<仮想ボタン
		DWORD keyCoord;			//!<キーボードのキーコード。
	};
	const VirtualPadToKeyboard vPadToKeyboardTable[enButtonNum] = {
		{ enButtonUp, '8' },
		{ enButtonDown, '2' },
		{ enButtonLeft, '4' },
		{ enButtonRight, '6' },
		{ enButtonA, 'J' },
		{ enButtonB, 'K' },
		{ enButtonY, 'I' },
		{ enButtonX, 'O' },
		{ enButtonSelect, VK_SPACE },
		{ enButtonStart, VK_RETURN },
		{ enButtonRB1, '7' },
		{ enButtonRB2, '8' },
		{ enButtonRB3, '9' },
		{ enButtonLB1, 'B' },
		{ enButtonLB2, 'N' },
		{ enButtonLB3, 'M' },
	};
}
Pad::Pad() :
padNo(0)
{
	memset(&state, 0, sizeof(state));
	memset(trigger, 0, sizeof(trigger));
	memset(press, 0, sizeof(press));
	lStickX = 0.0f;
	lStickY = 0.0f;
	rStickX = 0.0f;
	rStickY = 0.0f;
}
Pad::~Pad()
{
}
void Pad::Update()
{
	DWORD result = XInputGetState(padNo, &state.state);
	if (result == ERROR_SUCCESS) {
		//接続されている。
		padflag = true;
		state.bConnected = padflag;
		for (const VirtualPadToXPad& vPadToXPad : vPadToXPadTable) {
			if (state.state.Gamepad.wButtons & vPadToXPad.xButton) {
				trigger[vPadToXPad.vButton] = 1 ^ press[vPadToXPad.vButton];
				press[vPadToXPad.vButton] = 1;
			}
			else {
				trigger[vPadToXPad.vButton] = 0;
				press[vPadToXPad.vButton] = 0;
			}
		}
		if ((state.state.Gamepad.sThumbLX < INPUT_DEADZONE &&
			state.state.Gamepad.sThumbLX > -INPUT_DEADZONE) &&
			(state.state.Gamepad.sThumbLY < INPUT_DEADZONE &&
			state.state.Gamepad.sThumbLY > -INPUT_DEADZONE))
		{
			state.state.Gamepad.sThumbLX = 0;
			state.state.Gamepad.sThumbLY = 0;
			lStickX = 0.0f;
			lStickY = 0.0f;
		}
		else {
			//左スティックの入力量。
			if (state.state.Gamepad.sThumbLX > 0) {
				lStickX = s_cast<float>(state.state.Gamepad.sThumbLX) / SHRT_MAX;
			}
			else {
				lStickX = s_cast<float>(state.state.Gamepad.sThumbLX) / -SHRT_MIN;
			}
			if (state.state.Gamepad.sThumbLY > 0) {
				lStickY = s_cast<float>(state.state.Gamepad.sThumbLY) / SHRT_MAX;
			}
			else {
				lStickY = s_cast<float>(state.state.Gamepad.sThumbLY) / -SHRT_MIN;
			}
		}

		if ((state.state.Gamepad.sThumbRX < INPUT_DEADZONE &&
			state.state.Gamepad.sThumbRX > -INPUT_DEADZONE) &&
			(state.state.Gamepad.sThumbRY < INPUT_DEADZONE &&
			state.state.Gamepad.sThumbRY > -INPUT_DEADZONE))
		{
			state.state.Gamepad.sThumbRX = 0;
			state.state.Gamepad.sThumbRY = 0;
			rStickX = 0.0f;
			rStickY = 0.0f;
		}
		else {
			//右スティックの入力量。
			if (state.state.Gamepad.sThumbRX > 0) {
				rStickX = s_cast<float>(state.state.Gamepad.sThumbRX) / SHRT_MAX;
			}
			else {
				rStickX = s_cast<float>(state.state.Gamepad.sThumbRX) / -SHRT_MIN;
			}
			if (state.state.Gamepad.sThumbRY > 0) {
				rStickY = s_cast<float>(state.state.Gamepad.sThumbRY) / SHRT_MAX;
			}
			else {
				rStickY = s_cast<float>(state.state.Gamepad.sThumbRY) / -SHRT_MIN;
			}
		}
	}
	else {
		//接続されていない。
		if (state.bConnected) {
			//未接続になった。
			memset(&state, 0, sizeof(state));
			memset(trigger, 0, sizeof(trigger));
			memset(press, 0, sizeof(press));
			padflag = false;
		}
		lStickX = 0.0f;
		lStickY = 0.0f;
		rStickX = 0.0f;
		rStickY = 0.0f;

		if (GetAsyncKeyState(VK_LEFT)) {
			rStickX = -1.0f;
		}
		else if (GetAsyncKeyState(VK_RIGHT)) {
			rStickX = 1.0f;
		}
		if (GetAsyncKeyState(VK_UP)) {
			rStickY = 1.0f;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			rStickY = -1.0f;
		}
		//スティックの入力量を正規化。
		float t = fabsf(rStickX) + fabsf(rStickY);
		if (t > 0.0f) {
			rStickX /= t;
			rStickY /= t;
		}

		if (GetAsyncKeyState('A')) {
			lStickX = -1.0f;
		}
		else if (GetAsyncKeyState('D')) {
			lStickX = 1.0f;
		}
		if (GetAsyncKeyState('W')) {
			lStickY = 1.0f;
		}
		else if (GetAsyncKeyState('S')) {
			lStickY = -1.0f;
		}
		//スティックの入力量を正規化。
		t = fabsf(lStickX) + fabsf(lStickY);
		if (t > 0.0f) {
			lStickX /= t;
			lStickY /= t;
		}

		for (const VirtualPadToKeyboard& vPadToKeyboard : vPadToKeyboardTable) {
			if (GetAsyncKeyState(vPadToKeyboard.keyCoord)) {
				trigger[vPadToKeyboard.vButton] = 1 ^ press[vPadToKeyboard.vButton];
				press[vPadToKeyboard.vButton] = 1;
			}
			else {
				trigger[vPadToKeyboard.vButton] = 0;
				press[vPadToKeyboard.vButton] = 0;
			}
		}
	}
}