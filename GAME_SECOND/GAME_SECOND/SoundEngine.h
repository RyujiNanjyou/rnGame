/*!
 * @brief	�T�E���h�G���W��
 */

#pragma once

#define INPUTCHANNELS 2  // number of source channels
#define OUTPUTCHANNELS 8	//�ő�o�̓`�����l�����B
#include <xaudio2.h>
#include <x3daudio.h>
#include <xaudio2fx.h>
#include <list>
	class WaveFile;
	class SoundSource;
	/*!
	 * @brief	�T�E���h�G���W���B
	 */
	class SoundEngine{
	public:
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		SoundEngine();
		/*!
		 * @brief	�f�X�g���N�^�B
		 */
		~SoundEngine();
		/*!
		 * @brief	�������B
		 */
		void Init();
		/*!
		 * @brief	�J���B
		 */
		void Release();
		/*!
		* @brief	�X�V�B
		*/
		void Update();
		/*!
		* @brief	3D�T�E���h�\�[�X��ǉ��B
		*/
		void Add3DSoundSource(SoundSource* s)
		{
			soundSource.push_back(s);
		}
		/*!
		* @brief	3D�T�E���h�\�[�X���폜�B
		*/
		void Remove3DSoundSource(SoundSource* s)
		{
			auto& it = std::find(soundSource.begin(), soundSource.end(), s);
			if (it != soundSource.end()) {
				soundSource.erase(it);
			}
		}
		/*!
		* @brief	�T�E���h���X�i�[�̍��W��ݒ�B
		* @details
		*  3D�������g���Ă��鎞�̌v�Z�Ɏg�p����܂��B
		*/
		void SetListenerPosition(const D3DXVECTOR3& pos)
		{
			listenerPosition = pos;
		}
		/*!
		* @brief	�T�E���h���X�i�[�̑O������ݒ�B
		* @details
		*  3D�������g���Ă��鎞�̌v�Z�Ɏg�p����܂��B
		*/
		void SetListenerFront(D3DXVECTOR3 front)
		{
			listener.OrientFront.x = front.x;
			listener.OrientFront.y = front.y;
			listener.OrientFront.z = front.z;
		}
		/*!
		* @brief	�T�E���h���X�i�[�̏������ݒ�B
		* @details
		*  3D�������g���Ă��鎞�̌v�Z�Ɏg�p����܂��B
		*/
		void SetListenerUp(D3DXVECTOR3 up)
		{
			listener.OrientTop.x = up.x;
			listener.OrientTop.y = up.y;
			listener.OrientTop.z = up.z;
		}
		/*!
		* @brief	XAudio2�̃\�[�X�{�C�X���쐬�B
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
		* @brief	�o�̓`�����l���̐����擾�B
		*/
		int GetNumChannel() const
		{
			return nChannels;
		}
	private:
		IXAudio2* xAudio2 = nullptr;
		IXAudio2MasteringVoice* masteringVoice = nullptr;
		X3DAUDIO_HANDLE hx3DAudio;					//!<3D�I�[�f�B�I�̃n���h���B
		IUnknown* reverbEffect = nullptr;				//!<���o�[�v�G�t�F�N�g�B
		IXAudio2SubmixVoice* submixVoice = nullptr;	//!<�T�u�~�b�N�X�{�C�X�B
		DWORD channelMask = 0;						//!<�I�[�f�B�I�`�����l���}�X�N�B
		DWORD nChannels = 0;							//!<�`�����l�����B
		D3DXVECTOR3 listenerPosition = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//!<���X�i�[�̍��W�B
		float fListenerAngle = 0.0f;
		bool useListenerCone = false;
		bool fUseInnerRadius = false;
		bool useRedirectToLFE = false;
		bool isInited = false;
		X3DAUDIO_LISTENER listener;					//!<�T�E���h���X�i�[�B
		std::list<SoundSource*>	soundSource;	//!<3D�T�E���h�̃T�E���h�\�[�X�B
		X3DAUDIO_CONE	emitterCone;
	};
