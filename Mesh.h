#pragma once

#include <DirectXMath.h>

//Vertex Definition
struct Vertex
{
	DirectX::XMFLOAT3 position;	    // The local position of the vertex
	DirectX::XMFLOAT4 color;        // The color of the vertex
};

struct Index 
{
	int pointNum;
};

//Mesh Class
class Mesh {
	void MakeVertexBuffer();
	void MakeIndexBuffer();

	int GetVertexCount();
	int GetIndexCount();

	void Draw();

	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
};