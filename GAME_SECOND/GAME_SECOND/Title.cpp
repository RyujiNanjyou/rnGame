#include "stdafx.h"
#include "Title.h"


Title::Title()
{

}


Title::~Title()
{

}

void Title::Init()
{
	title.Init("Assets/Model/Title.png");
	title.SetPivot({ 0.5f, 0.25f });
	title.Setpos(D3DXVECTOR3(0.0f,0.0f, 0.0f));
	title.Setsize(D3DXVECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT));

}
void Title::Update()
{

}

void Title::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	title.Render(viewMatrix, projMatrix);
}