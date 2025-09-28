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

	void MakeVertexBuffer(int vertCount);
	void MakeIndexBuffer(int indxCount);

	int GetVertexCount();
	int GetIndexCount();

	void Draw();

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;
};
