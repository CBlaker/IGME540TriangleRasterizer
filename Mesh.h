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

//Mesh Class
class Mesh {
public:

	void MakeVertexBuffer(Vertex verticies[], int vertCount);
	void MakeIndexBuffer(Index indicies[], int indxCount);

	int GetVertexCount(Vertex vertices[]);
	int GetIndexCount(Index indices[]);

	void Draw();

private:
	int VertexCount;
	int IndexCount;

	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
};
