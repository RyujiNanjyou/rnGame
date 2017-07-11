/*!
*@brief	パッド
*/
#pragma once
#include <XInput.h> // XInput API
	/*!
	*@brief	仮想ボタン定義。
	*/
enum EnButton{
	enButtonUp,		//!<上。
	enButtonDown,		//!<下。
	enButtonLeft,		//!<左。
	enButtonRight,		//!<右。
	enButtonA,			//!<Aボタン。
	enButtonB,			//!<Bボタン。
	enButtonX,			//!<Xボタン。
	enButtonY,			//!<Yボタン。
	enButtonSelect,	//!<セレクトボタン。
	enButtonStart,		//!<スタートボタン。
	enButtonRB1,		//!<RB1ボタン。
	enButtonRB2,		//!<RB2ボタン。
	enButtonRB3,		//!<RB3ボタン。
	enButtonLB1,		//!<LB1ボタン。
	enButtonLB2,		//!<LB2ボタン。
	enButtonLB3,		//!<LB3ボタン。
	enButtonNum,	//!<ボタンの数。
};
	/*!
	*@brief	パッド
	*/
class Pad{
public:
	/*!
	*@brief	パッドステート。
	*/
	struct PAD_STATE
	{
		XINPUT_STATE state;
		bool bConnected;
	};
	/*!
	*@brief	コンストラクタ。
	*/
	Pad();
	/*!
	*@brief	デストラクタ。
	*/
	~Pad();
	/*!
	*@brief	初期化。
	*@param[in]	padNo	パッド番号。
	*/
	void Init(int padNo)
	{
		padNo = padNo;
	}
	/*!
	*@brief	更新。
	*/
	void Update();
	/*!
	*@brief	ボタンのトリガー判定。
	*@return	trueが返ってきたらトリガー入力。
	*/
	bool IsTrigger(EnButton button) const
	{
		//TK_ASSERT(button < enButtonNum, "button is invalid");
		return trigger[button] != 0;
	}
	/*!
	*@brief	ボタンが押されているか判定。
	*@return	trueが返ってきたら押されている。
	*/
	bool IsPress(EnButton button) const
	{
		//TK_ASSERT(button < enButtonNum, "button is invalid");
		return press[button] != 0;
	}
	/*!
	*@brief	左スティックのX軸の入力量を取得。
	*@return	-1.0～1.0の正規化された値を返す。
	*/
	float GetLStickXF() const
	{
		return lStickX;
	}
	/*!
	*@brief	左スティックのY軸の入力量を取得。
	*@return	-1.0～1.0の正規化された値を返す。
	*/
	float GetLStickYF() const
	{
		return lStickY;
	}
	/*!
	*@brief	右スティックのX軸の入力量を取得。
	*@return	-1.0～1.0の正規化された値を返す。
	*/
	float GetRStickXF() const
	{
		return rStickX;
	}
	/*!
	*@brief	右スティックのY軸の入力量を取得。
	*@return	-1.0～1.0の正規化された値を返す。
	*/
	float GetRStickYF() const
	{
		return rStickY;
	}
	bool Getf(){ return padflag; }
	void Setf(bool f){ padflag = f; }
private:
	PAD_STATE state;	//!<パッドステート。
	int padNo;		//!<パッド番号。
	int trigger[enButtonNum];	//!<トリガー入力のフラグ。
	int press[enButtonNum];	//!<press入力のフラグ。
	float lStickX;			//!<左スティックのX軸の入力量。
	float lStickY;			//!<左スティックのY軸の入力量。
	float rStickX;			//!<右スティックのX軸の入力量。
	float rStickY;			//!<右スティックのY軸の入力量。
	bool padflag;
};