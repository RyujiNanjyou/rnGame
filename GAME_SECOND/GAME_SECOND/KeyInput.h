/*!
* @brief	キー入力。
*/

#ifndef _TKKEYINPUT_H_ 
#define _TKKEYINPUT_H_ 

#include "Pad.h"
	class CKeyInput{

	public:
		static const int NUM_PAD = 4;	//パッドの数。
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
		* @brief	コンストラクタ。
		*/
		CKeyInput();
		/*!
		* @brief	デストラクタ。
		*/
		~CKeyInput();
		/*!
		* @brief	キー情報の更新。
		*/
		void Update();
		/*!
		* @brief	上キーが押されている。
		*/
		bool IsUpPress() const
		{
			return keyPressFlag[enKeyUp];
		}
		/*!
		* @brief	右キーが押されている。
		*/
		bool IsRightPress() const
		{
			return keyPressFlag[enKeyRight];
		}
		/*!
		* @brief	左キーが押されている。
		*/
		bool IsLeftPress() const
		{
			return keyPressFlag[enKeyLeft];
		}
		/*!
		* @brief	下キーが押されている。
		*/
		bool IsDownPress() const
		{
			return keyPressFlag[enKeyDown];
		}
		/*!
		* @brief	キーのプレス判定。
		*/
		bool IsPress(EnKey key) const
		{
			return keyPressFlag[key];
		}
		/*!
		* @brief	キーのトリガー判定。
		*/
		bool IsTrgger(EnKey key) const
		{
			return keyTrigerFlag[key];
		}
		/*!
		* @brief	マウスの左ボタンが離されたときの処理。
		*/
		void OnMouseLButtonUp(int x, int y)
		{
			mousePositionX = x;
			mousePositionY = y;
			isMouseUp[1] = true;
		}
		/*!
		* @brief	マウスの左ボタンが離されたときか判定。
		*/
		bool IsMouseLButtonUp() const
		{
			return isMouseUp[0];
		}
		/*!
		* @brief	マウスのX座標を取得。
		*/
		int GetMousePositionX() const
		{
			return mousePositionX;
		}
		/*!
		* @brief	マウスのY座標を取得。
		*/
		int GetMousePositionY() const
		{
			return mousePositionY;
		}
		/*!
		* @brief	ゲームパッドを取得。
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
		Pad		pad[NUM_PAD];		//!<パッド。
	};

#endif //_TKKEYINPUT_H_ 