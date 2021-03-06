/*!
 * @brief	シャドウマップ。
 */
struct VS_INPUT
{
	float4	Position	: POSITION;
};
struct VS_OUTPUT
{
	float4 Position	: POSITION;
	
};

float4x4	g_mWVP;		//ワールドビュープロジェクション行列。
float2		g_farNear;	//遠平面と近平面。xに遠平面、yに近平面。

VS_OUTPUT VSMain( VS_INPUT In )
{
	VS_OUTPUT Out = (VS_OUTPUT)0;
	Out.Position = mul(In.Position, g_mWVP);
	return Out;
}

float4 PSMain( VS_OUTPUT In ) : COLOR
{
	return float4(0.5f, 0.5f, 0.5f, 1.0f);
}


technique RenderShadowMap
{
	pass p0
	{
		VertexShader 	= compile vs_3_0 VSMain();
		PixelShader 	= compile ps_3_0 PSMain();
	}
}

