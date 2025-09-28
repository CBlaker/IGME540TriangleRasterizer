#pragma once

#include <DirectXMath.h>

//Vertex Definition
struct Vertex
{
	DirectX::XMFLOAT3 position;	    // Position
	DirectX::XMFLOAT4 color;        // Color
};

//Index Definition
struct Index 
{
	int pointNum; //Index
};
//Color Definitions
XMFLOAT4 red = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
XMFLOAT4 green = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
XMFLOAT4 blue = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);


//Mesh 1 Vertex Data
Vertex vertices[] =
{
	{ XMFLOAT3(+0.0f, +0.5f, +0.0f), red },
	{ XMFLOAT3(+0.5f, -0.5f, +0.0f), blue },
	{ XMFLOAT3(-0.5f, -0.5f, +0.0f), green },
};

Index indices[] = { 0, 1, 2 };

//Mesh 2 Vertex Data



//Mesh Class
class Mesh {
public:

	void MakeVertexBuffer(Vertex verticies[], int vertCount);
	void MakeIndexBuffer(Index indicies[], int indxCount);

	int GetVertexCount(Vertex vertexes[]);
	int GetIndexCount(Index indicies[]);

	void Draw(int indxCount);

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
};
