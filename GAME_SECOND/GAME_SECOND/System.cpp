#include "stdafx.h"

#include <windowsx.h>


LPDIRECT3D9				g_pD3D = NULL;
LPDIRECT3DDEVICE9		g_pd3dDevice = NULL;
HWND					g_hwnd = NULL;
EffectManager*			effectmanager = NULL;


extern void Init();
extern void Render();
extern void Update();
extern void Terminate();

//DirectX ������
void InitD3D(HWND hWnd)
{
	//D3D�I�u�W�F�N�g���쐬
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

	//D3D�f�o�C�X���쐬���邽�߂̃p�����[�^��ݒ�
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	//D3D�f�o�C�X�쐬
	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &g_pd3dDevice);

	effectmanager = new EffectManager;
	soundengine = new SoundEngine;

}
//���b�Z�[�W�v���V�[�W��
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		if (g_pd3dDevice != NULL)
			g_pd3dDevice->Release();
		if (g_pD3D != NULL)
			g_pD3D->Release();
		Terminate();
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//�E�B�����C��
INT  WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, LPWSTR, INT)
{
	UNREFERENCED_PARAMETER(hInst);

	// �E�B���h�E�N���X��o�^�B
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"GAME_SECOND", NULL
	};
	RegisterClassEx(&wc);

	// �E�B���h�E���쐬�B
	HWND hWnd = CreateWindow("GAME_SECOND", "GAME_SECOND",
		WS_OVERLAPPEDWINDOW, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT,
		NULL, NULL, wc.hInstance, NULL);
	g_hwnd = hWnd;

	// Direct3D���������B
	InitD3D(hWnd);
	

	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	ShowCursor(TRUE);
	//��������Q�[���֌W�̏������B
	Init();

	// �Q�[�����[�v
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			Update();
			Render();
			
		}
	}
	UnregisterClass("GAME_SECOND", wc.hInstance);
	return 0;
}