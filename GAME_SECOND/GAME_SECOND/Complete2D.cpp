#include "stdafx.h"
#include "Complete2D.h"


Complete2D::Complete2D()
{
}


Complete2D::~Complete2D()
{
}
void Complete2D::Init()
{
	float doihumikun = 721;
	comp2D.Init("Assets/Model/comp.png");
	comp2D.SetPivot({ 0.5f, 0.25f });
	comp2D.Setpos(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	comp2D.Setsize(D3DXVECTOR2(WINDOW_WIDTH, WINDOW_HEIGHT));
}

void Complete2D::Update()
{

}

void Complete2D::Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix)
{
	comp2D.Render(viewMatrix, projMatrix);
}