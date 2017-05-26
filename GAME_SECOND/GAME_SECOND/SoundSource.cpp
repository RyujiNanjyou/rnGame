/*!
 * @brief	�����N���X�B
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
		//�T�E���h�{�C�X�\�[�X���쐬�B
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
		//�T�E���h�{�C�X�\�[�X���쐬�B
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
			//�Đ��J�n�B
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
			//�����O�o�b�t�@�̃T�C�Y�𒴂���B
			//�z����B
			readStartPos = 0;
		}
		waveFile.ReadAsync(&readStartBuff[readStartPos], streamingBufferSize, &currentBufferingSize);
		streamingState = enStreamingBuffering;
	}
	void SoundSource::Play(bool isLoop)
	{
		if (isPlaying) {
			//�Đ����̂��̂��ĊJ����B
			sourceVoice->Start(0);
		}
		else {
			if (isStreaming) {
				//�o�b�t�@�����O�J�n
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
			//�o�b�t�@�����O���B
			if (waveFile.IsReadEnd()) {
				//�o�b�t�@�����O���I������B
				streamingState = enStreamingQueueing;
			}
		}
		if (streamingState == enStreamingQueueing) {
			//�L���[�C���O���B
			XAUDIO2_VOICE_STATE state;
			sourceVoice->GetState(&state);
			if (state.BuffersQueued <= 2) {	//�L���[�C���O����Ă���o�b�t�@���Q�ȉ��ɂȂ�����L���[�C���O�ł���B
				Play(&buffer[readStartPos], currentBufferingSize);
				if (currentBufferingSize == 0) {
					//�ǂݍ��񂾃T�C�Y���O�Ƃ������Ƃ͖��[�܂œǂݍ��݂��I������Ƃ������ƁB
					if (isLoop) {
						//���[�v����H
						//wave�t�@�C���̓ǂݍ��݈ʒu�����Z�b�g���ăo�b�t�@�����O�ĊJ�B
						waveFile.ResetFile();
						StartStreamingBuffring();
					}
					else {
						//���[�v���Ȃ��ꍇ�̓L���[����ɂȂ�����Đ��I���B
						if (state.BuffersQueued == 0) {
							//�Đ��I���B
							isPlaying = false;
							delete(this);
							Remove3DSound();
						}
					}
				}
				else {
					//�����o�b�t�@�����O����B
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
				//���[�v�B
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
			//�X�g���[�~���O�Đ����̍X�V�B
			UpdateStreaming();
		}
		else {
			//�I���������Đ����̍X�V�����B
			UpdateOnMemory();
		}
		if (is3DSound == true) {
			//�����̈ړ����x���X�V�B
			m_velocity = position - m_lastFramePosition;
			m_velocity /= (1.0f/60.0f);
			m_lastFramePosition = position;
		}
	}
