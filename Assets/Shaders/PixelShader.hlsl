
// Defines the input to this pixel shader
// - Should match the output of our corresponding vertex shader
struct VertexToPixel
{
	float4 position		: SV_POSITION;
	float3 normal       : NORMAL;
	float3 worldPos     : TEXCOORD0;
	float2 uv			: TEXCOORD1;
};


struct DirectionalLight 
{
	float4 AmbientColor;
	float4 DiffuseColor;
	float3 Direction;
};

cbuffer externalData : register(b0) 
{
	DirectionalLight light1;
	DirectionalLight light2;
}

Texture2D diffuseTexture : register(t0);
//Texture2D metalTexture : register(t1);

SamplerState trilinear : register(s0);

float4 calcDirLight(DirectionalLight light, float3 normal) 
{
	// Light Direction
	float3 lightDir = normalize(light.Direction);

	// Light Amount
	float dirNdotL = saturate(dot(normal, -lightDir));

	// Return Color
	return light.DiffuseColor * dirNdotL + light.AmbientColor;
}

// --------------------------------------------------------
// The entry point (main method) for our pixel shader
// 
// - Input is the data coming down the pipeline (defined by the struct)
// - Output is a single color (float4)
// --------------------------------------------------------
float4 main(VertexToPixel input) : SV_TARGET
{
	// Normalize 
	input.normal = normalize(input.normal);

	float4  diffuseColor = diffuseTexture.Sample(trilinear, input.uv);

	return diffuseColor * calcDirLight(light1, input.normal) +  diffuseColor * (calcDirLight(light2, input.normal));
}