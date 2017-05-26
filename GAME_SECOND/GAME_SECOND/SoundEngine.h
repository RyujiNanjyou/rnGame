/*!
 * @brief	サウンドエンジン
 */

#pragma once

#define INPUTCHANNELS 2  // number of source channels
#define OUTPUTCHANNELS 8	//最大出力チャンネル数。
#include <xaudio2.h>
#include <x3daudio.h>
#include <xaudio2fx.h>
#include <list>
	class WaveFile;
	class SoundSource;
	/*!
	 * @brief	サウンドエンジン。
	 */
	class SoundEngine{
	public:
		/*!
		 * @brief	コンストラクタ。
		 */
		SoundEngine();
		/*!
		 * @brief	デストラクタ。
		 */
		~SoundEngine();
		/*!
		 * @brief	初期化。
		 */
		void Init();
		/*!
		 * @brief	開放。
		 */
		void Release();
		/*!
		* @brief	更新。
		*/
		void Update();
		/*!
		* @brief	3Dサウンドソースを追加。
		*/
		void Add3DSoundSource(SoundSource* s)
		{
			soundSource.push_back(s);
		}
		/*!
		* @brief	3Dサウンドソースを削除。
		*/
		void Remove3DSoundSource(SoundSource* s)
		{
			auto& it = std::find(soundSource.begin(), soundSource.end(), s);
			if (it != soundSource.end()) {
				soundSource.erase(it);
			}
		}
		/*!
		* @brief	サウンドリスナーの座標を設定。
		* @details
		*  3D音源を使っている時の計算に使用されます。
		*/
		void SetListenerPosition(const D3DXVECTOR3& pos)
		{
			listenerPosition = pos;
		}
		/*!
		* @brief	サウンドリスナーの前方向を設定。
		* @details
		*  3D音源を使っている時の計算に使用されます。
		*/
		void SetListenerFront(D3DXVECTOR3 front)
		{
			listener.OrientFront.x = front.x;
			listener.OrientFront.y = front.y;
			listener.OrientFront.z = front.z;
		}
		/*!
		* @brief	サウンドリスナーの上方向を設定。
		* @details
		*  3D音源を使っている時の計算に使用されます。
		*/
		void SetListenerUp(D3DXVECTOR3 up)
		{
			listener.OrientTop.x = up.x;
			listener.OrientTop.y = up.y;
			listener.OrientTop.z = up.z;
		}
		/*!
		* @brief	XAudio2のソースボイスを作成。
		*/
		IXAudio2SourceVoice* CreateXAudio2SourceVoice(WaveFile* waveFile, bool is3DSound);
		IXAudio2MasteringVoice* GetMasteringVoice()
		{
			return masteringVoice;
		}
		IXAudio2SubmixVoice* GetSubmixVoice()
		{
			return submixVoice;
		}
		/*!
		* @brief	出力チャンネルの数を取得。
		*/
		int GetNumChannel() const
		{
			return nChannels;
		}
	private:
		IXAudio2* xAudio2 = nullptr;
		IXAudio2MasteringVoice* masteringVoice = nullptr;
		X3DAUDIO_HANDLE hx3DAudio;					//!<3Dオーディオのハンドル。
		IUnknown* reverbEffect = nullptr;				//!<リバープエフェクト。
		IXAudio2SubmixVoice* submixVoice = nullptr;	//!<サブミックスボイス。
		DWORD channelMask = 0;						//!<オーディオチャンネルマスク。
		DWORD nChannels = 0;							//!<チャンネル数。
		D3DXVECTOR3 listenerPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//!<リスナーの座標。
		float fListenerAngle = 0.0f;
		bool useListenerCone = false;
		bool fUseInnerRadius = false;
		bool useRedirectToLFE = false;
		bool isInited = false;
		X3DAUDIO_LISTENER listener;					//!<サウンドリスナー。
		std::list<SoundSource*>	soundSource;	//!<3Dサウンドのサウンドソース。
		X3DAUDIO_CONE	emitterCone;
	};
