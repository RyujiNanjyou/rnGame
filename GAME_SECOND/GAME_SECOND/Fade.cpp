#include "stdafx.h"
#include "Fade.h"



Fade::Fade()
{
}


Fade::~Fade()
{
}
bool Fade::Start()
{
	
	sprite.Init("Assets//Model/Fade,png");
	sprite.Setsize(D3DXVECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT));
	activeFlag = false;
	sprite.Setalpha(0.0f);
	return true;
}
void Fade::Update()
{
	if (isExecute) {
		switch (state) {
		case eFadeOut: {
			timer += 1.0f/60.0f;
			if (timer < FADE_TIME) {
				float t = timer / FADE_TIME;
				sprite.Setalpha(min(t, 1.0f));
			}
			else {
				isExecute = false;
				sprite.Setalpha(1.0f);
			}
		}break;
		case eFadeIn:
			timer += timer += 1.0f/60.0f;
			if (timer < FADE_TIME) {
				float t = timer / FADE_TIME;
				sprite.Setalpha(max(1.0f - t, 0.0f));
			}
			else {
				//透明になったので非アクティブにする。
				sprite.Setalpha(0.0f);
				activeFlag = false;
				isExecute = false;
			}
			break;
		}
	}
}
void Fade::PostRender()
{
	D3DXMATRIX identity;
	D3DXMatrixIdentity(&identity);
	sprite.Render(identity, identity);
}
