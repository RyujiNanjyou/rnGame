/*!
 * @brief	音源クラス。
 */
#include "stdafx.h"
#include "tkEnginePreCompile.h"
#include "SoundEngine.h"
#include "SoundSource.h"


	SoundSource::SoundSource()
	{
		soundengine->SetListenerPosition({10.0f, 0.0f, 0.0f});
		memset(m_emitterAzimuths, 0, sizeof(m_emitterAzimuths));
		memset(m_matrixCoefficients, 0, sizeof(m_matrixCoefficients));
	}
	SoundSource::~SoundSource()
	{
		Release();
	}
	void SoundSource::InitCommon()
	{
		m_dspSettings.SrcChannelCount = INPUTCHANNELS;
		m_dspSettings.DstChannelCount = soundengine->GetNumChannel();
		m_dspSettings.pMatrixCoefficients = m_matrixCoefficients;
		m_dspSettings.pDelayTimes = nullptr;
		m_dspSettings.DopplerFactor = 1.0f;
		m_dspSettings.LPFDirectCoefficient = 0.82142854f;
		m_dspSettings.LPFReverbCoefficient = 0.75f;
		m_dspSettings.ReverbLevel = 0.69114286f;
		m_dspSettings.EmitterToListenerAngle = 0.0f;
		m_dspSettings.EmitterToListenerDistance = 10.0f;
		m_dspSettings.EmitterVelocityComponent = 0.0f;
		m_dspSettings.ListenerVelocityComponent = 0.0f;
	}
	void SoundSource::Init( char* filePath, bool is3DSound )
	{
		waveFile.Open(filePath);
		buffer.reset(new char[waveFile.GetSize()]);
		unsigned int dummy;
		waveFile.Read(buffer.get(), waveFile.GetSize(), &dummy);
		//サウンドボイスソースを作成。
		sourceVoice = soundengine->CreateXAudio2SourceVoice(&waveFile, is3DSound);
		if (is3DSound) {
			soundengine->Add3DSoundSource(this);
		}
		InitCommon();
		

		is3DSound = is3DSound;
	}
	void SoundSource::InitStreaming(char* filePath, bool is3DSound, unsigned int ringBufferSize, unsigned int bufferSize)
	{
		waveFile.Open(filePath);
		isStreaming = true;
		streamingBufferSize = bufferSize;
		buffer.reset( new char[ringBufferSize]);
		this->ringBufferSize = ringBufferSize;
		readStartPos = 0;
		currentBufferingSize = 0;
		//サウンドボイスソースを作成。
		sourceVoice = soundengine->CreateXAudio2SourceVoice(&waveFile, is3DSound);
		sourceVoice->Start(0,0);
		if (is3DSound) {
			soundengine->Add3DSoundSource(this);
		}
		InitCommon();
		
		is3DSound = is3DSound;
	}
	void SoundSource::Release()
	{
		waveFile.Release();
		if (sourceVoice != nullptr) {
			sourceVoice->DestroyVoice();
			sourceVoice = nullptr;
		}
		Remove3DSound();
	}
	void SoundSource::Play(char* buff, unsigned int bufferSize)
	{
		XAUDIO2_BUFFER buffer = { 0 };
		buffer.pAudioData = (BYTE*)buff;
		buffer.Flags = XAUDIO2_END_OF_STREAM;  // tell the source voice not to expect any data after this buffer
		buffer.AudioBytes = bufferSize;
		if (sourceVoice != nullptr && bufferSize > 0) {
			//再生開始。
			if (FAILED(sourceVoice->SubmitSourceBuffer(&buffer))) {
				Release();
				TK_LOG("Failed sourceVoice->SubmitSourceBuffer");
				return;
			}

		}
	}
	
	void SoundSource::StartStreamingBuffring()
	{
		char* readStartBuff = buffer.get();
		readStartPos += currentBufferingSize;
		if (readStartPos + streamingBufferSize >= ringBufferSize) {
			//リングバッファのサイズを超える。
			//循環する。
			readStartPos = 0;
		}
		waveFile.ReadAsync(&readStartBuff[readStartPos], streamingBufferSize, &currentBufferingSize);
		streamingState = enStreamingBuffering;
	}
	void SoundSource::Play(bool isLoop)
	{
		if (isPlaying) {
			//再生中のものを再開する。
			sourceVoice->Start(0);
		}
		else {
			if (isStreaming) {
				//バッファリング開始
				StartStreamingBuffring();
			}
			else {
				sourceVoice->FlushSourceBuffers();
				sourceVoice->Start(0);
				Play(buffer.get(), waveFile.GetSize());
			}
			isPlaying = true;
		}
		this->isLoop = isLoop;
	}
	void SoundSource::UpdateStreaming()
	{
		if (!isPlaying) {
			return;
		}
		if (streamingState == enStreamingBuffering) {
			//バッファリング中。
			if (waveFile.IsReadEnd()) {
				//バッファリングが終わった。
				streamingState = enStreamingQueueing;
			}
		}
		if (streamingState == enStreamingQueueing) {
			//キューイング中。
			XAUDIO2_VOICE_STATE state;
			sourceVoice->GetState(&state);
			if (state.BuffersQueued <= 2) {	//キューイングされているバッファが２以下になったらキューイングできる。
				Play(&buffer[readStartPos], currentBufferingSize);
				if (currentBufferingSize == 0) {
					//読み込んだサイズが０ということは末端まで読み込みが終わったということ。
					if (isLoop) {
						//ループする？
						//waveファイルの読み込み位置をリセットしてバッファリング再開。
						waveFile.ResetFile();
						StartStreamingBuffring();
					}
					else {
						//ループしない場合はキューが空になったら再生終了。
						if (state.BuffersQueued == 0) {
							//再生終了。
							isPlaying = false;
							delete(this);
							Remove3DSound();
						}
					}
				}
				else {
					//次をバッファリングする。
					StartStreamingBuffring();
				}
			}
		}
	}
	void SoundSource::Remove3DSound()
	{
		if (is3DSound) {
			soundengine->Remove3DSoundSource(this);
			is3DSound = false;
		}
	}
	void SoundSource::UpdateOnMemory()
	{
		if (!isPlaying) {
			return;
		}
		XAUDIO2_VOICE_STATE state;
		sourceVoice->GetState(&state);
		if (state.BuffersQueued <= 0) {
			isPlaying = false;
			if (isLoop) {
				//ループ。
				Play(isLoop);
			}
			else {
				delete(this);
				Remove3DSound();
			}
		}
	}
	void SoundSource::Update()
	{
		if (isStreaming) {
			//ストリーミング再生中の更新。
			UpdateStreaming();
		}
		else {
			//オンメモリ再生中の更新処理。
			UpdateOnMemory();
		}
		if (is3DSound == true) {
			//音源の移動速度を更新。
			m_velocity = position - m_lastFramePosition;
			m_velocity /= (1.0f/60.0f);
			m_lastFramePosition = position;
		}
	}
