/*!
 * @brief	音源クラス。
 */

#pragma once
#include <xaudio2.h>
#include <x3daudio.h>
#include <xaudio2fx.h>
#include "WaveFile.h"
#include <memory>


	/*!
	 * @brief	音源クラス。
	 *@details
	 * このクラスには波形データをオンメモリに乗せて再生する方法と、ストリーミング再生する方法があります。</br>
	 * オンメモリに乗せる場合はSoundSource::Initを使って初期化を行ってください。</br>
	 * ストリーミング再生を行う場合はSoundSource::InitStreamingを使用してください。</br>
	 * オンメモリでの再生は波形データを全てメインメモリ上に乗せて再生を行う方法です。</br>
	 * ストリーミング再生はメディア(DVD、HDDなどの外部補助記憶装置)から少しづつ読み込みを行って、</br>
	 * 逐次実行していく方法です。ストリーミング再生は必要な分だけ読み込みを行い(バッファリング)を行い、</br>
	 * 再生が完了するとそのバッファを破棄します。このため、少ないメモリで大きな波形データを再生することが可能です。</br>
	 * オンメモリ再生は読み込みのオーバーヘッドが最初だけになるが、ストリーミング再生は常に読み込みのオーバーヘッドが</br>
	 * 発生するためパフォマーンスが低下します。</br>
	 * 一般的にオンメモリ再生は効果音などのようなサイズの小さなSEの再生に適しています。</br>
	 * ストリーミング再生は大きなサイズのBGMの再生に適しています。</br>
	 *
	 * このクラスのインスタンスをゲームオブジェクトマネージャーに登録した場合、ループ再生ではない場合は再生が完了すると</br>
	 * 自動的に登録解除されます。ループ再生の場合はユーザーが明示的に登録を解除する必要があります。
	 *@code
	 	SoundSource soundSource;
	 	//初期化
	 	void Init()
	 	{
		 	soundSource.Init("test.wave");				//こちらで初期化するとオンメモリ再生。
		 	//soundSource.InitStreaming("test.wave");	//こちらで初期化するとストリーミング再生。
		 	soundSource.Play(true);
		}
	 	//更新処理
	 	void Update()
	 	{
	 		soundSource.Update();
		}
	 	
	 *@endcode
	 */
	class SoundSource{
	public:
		/*!
		 * @brief	コンストラクタ。
		 */
		SoundSource();
		/*!
		 * @brief	デストラクタ。
		 */
		~SoundSource();
		/*!
		 * @brief	初期化。
		 *@details
		 * オンメモリ再生向けの初期化。
		 *@param[in]	filePath	ファイルパス。対応しているファイルフォーマット(*.wave)
		 *@param[in]	is3DSound	3Dサウンド？
		 */
		void Init(char* filePath, bool is3DSound = false );
		/*!
		* @brief	初期化。
		*@details
		* ストリーミング再生向けの初期化。
		*@details
		* リングバッファにストリーミング読み込みを行って、再生を行っていきます。</br>
		* 一度に読み込まれるデータの最大サイズはbufferingSizeです。</br>
		* 読み込まれたデータはリングバッファにコピーされていきます。</br>
		*@param[in]	filePath		ファイルパス。対応しているファイルフォーマット(*.wave)
		*@param[in] is3DSound		3Dサウンド？
		*@param[in] ringBufferSize	リングバッファのサイズ。(bufferSizeの倍数になっていると無駄なく活用できます。)
		*@param[in]	bufferSize		ストリーミングの最大バッファリングサイズ。
		*/
		void InitStreaming(char* filePath, bool is3DSound = false, unsigned int ringBufferSize = 3 * 1024 * 1024, unsigned int bufferingSize = 1024 * 512);
		/*!
		* @brief	開放。
		*@details
		* デストラクタから自動的に呼ばれます。明示的に開放を行いたい場合に使用してください。
		*/
		void Release();
		/*!
		* @brief	再生。
		*@param[in]	isLoop		ループ再生フラグ。
		*/
		void Play(bool isLoop);
		/*!
		* @brief	停止。
		*/
		void Stop()
		{
			sourceVoice->Stop();
		}
		/*!
		* @brief	更新。
		*@param[in]	isLoop		ループ再生フラグ。
		*/
		void Update();
		/*!
		* @brief	ボリュームを設定。
		*@param[in]	vol		ボリューム。
		*/
		void SetVolume(float vol)
		{
			sourceVoice->SetVolume(vol);
		}
		/*!
		* @brief	音源の座標を設定。
		* @details
		*  3Dサウンドの時に必要になります。
		*  2Dサウンドでは無視されます。
		*@param[in] pos		音源の座標。
		*/
		void SetPosition(const D3DXVECTOR3& pos)
		{
			position = pos;
			if (m_isSetPositionFirst) {
				m_lastFramePosition = position;
				m_isSetPositionFirst = false;
			}
		}
		/*!
		* @brief	音源の座標を取得。
		*/
		D3DXVECTOR3 GetPosition() const
		{
			return position;
		}
		/*!
		* @brief	音源の移動速度を取得。
		*/
		D3DXVECTOR3 GetVelocity() const
		{
			return m_velocity;
		}
		IXAudio2SourceVoice* GetXAudio2SourceVoice()
		{
			return sourceVoice;
		}
		//入力チャンネル数を取得。
		int GetNumInputChannel()const
		{
			return waveFile.GetFormat()->nChannels;
		}
		FLOAT32* GetEmitterAzimuths() 
		{
			return m_emitterAzimuths;
		}
		FLOAT32* GetMatrixCoefficients() 
		{
			return m_matrixCoefficients;
		}
		X3DAUDIO_DSP_SETTINGS* GetDspSettings()
		{
			return &m_dspSettings;
		}
	private:
		void InitCommon();
		//ストリーミング再生中の更新処理。
		void UpdateStreaming();
		//オンメモリ再生中の更新処理。
		void UpdateOnMemory();
		void Play(char* buff, unsigned int bufferSize);
		/*!
		* @brief	ストリーミングバッファリングの開始。
		*/
		void StartStreamingBuffring();
		void Remove3DSound();
	private:
		enum EnStreamingStatus {
			enStreamingBuffering,	//バッファリング中。
			enStreamingQueueing,	//キューイング中。
		};
		WaveFile				waveFile;					//!<波形データ。
		std::unique_ptr<char[]>	buffer;					//!<波形データを読み込むバッファ。ストリーミング再生の時はリングバッファとして利用される。
		IXAudio2SourceVoice*	sourceVoice = nullptr;	//!<ソースボイス。
		bool					isLoop = false;			//!<ループフラグ。
		bool					isPlaying = false;		//!<再生中フラグ。
		bool					isStreaming = false;		//!<ストリーミング再生？
		unsigned int			streamingBufferSize = 0;	//!<ストリーミング用のバッファリングサイズ。
		unsigned int			currentBufferingSize = 0;	//!<現在のバッファリングのサイズ。
		unsigned int			readStartPos = 0;			//!<読み込み開始位置。
		unsigned int			ringBufferSize = 0;		//!<リングバッファのサイズ。
		EnStreamingStatus		streamingState = enStreamingBuffering;	//!<ストリーミングステータス。
		bool					is3DSound = false;		//!<3Dサウンド？
		D3DXVECTOR3				position = D3DXVECTOR3(0.0f,0.0f,0.0f);	//!<音源の座標。3Dサウンドの時に必要。
		D3DXVECTOR3				m_lastFramePosition = D3DXVECTOR3(0.0f,0.0f,0.0f);//!<音源の1フレーム前の座標。3Dサウンドの時に必要。
		D3DXVECTOR3				m_velocity = D3DXVECTOR3(0.0f,0.0f,0.0f);	//!<速度。3Dサウンドの時に必要・
		FLOAT32 m_emitterAzimuths[INPUTCHANNELS];
		FLOAT32 m_matrixCoefficients[INPUTCHANNELS * OUTPUTCHANNELS];
		X3DAUDIO_DSP_SETTINGS m_dspSettings;
		bool m_isSetPositionFirst = true;	//!<一番最初のsetPosition?
	};
