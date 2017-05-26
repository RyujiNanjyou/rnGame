// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

//#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define USE_VSM		//��`��VSM���L���B

#define USE_ORTHO_PROJECTION

/*!
* @brief	��`��DirectX9�œ���
*/
#define TK_PLATFORM_DX9

#if defined( TK_PLATFORM_DX9 )
#include <windows.h>
#endif // #if defined( TK_PLATFORM_DX9 )
#include <memory>
#include <XInput.h> // XInput API
#include <xaudio2.h>
#include <x3daudio.h>
#include <xaudio2fx.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "Xinput.lib")
#ifdef _DEBUG
#include <DxErr.h>
#pragma comment(lib, "dxerr.lib")
#endif
#include <list>
#include <vector>
#include <map>
#include <algorithm>


#include "typedef.h"
#include "tkAssert.h"
#include "tkLog.h"
#include "tkNoncopyable.h"
#include "KeyInput.h"



// TODO: reference additional headers your program requires here