struct VertexOut
{
	float4 position : SV_POSITION;
	float4 color : Color;
};

VertexOut main(float4 position : Position, float4 color : Color)
{
	VertexOut vOut;

	vOut.position = position;
	vOut.color = color;

	return vOut;
}