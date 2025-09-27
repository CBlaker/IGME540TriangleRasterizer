#include "Graphics.h"
#include "Mesh.h"

#include <d3d11.h>
#include <wrl/client.h>
#include <DirectXMath.h>

// For the DirectX Math library
using namespace DirectX;


XMFLOAT4 red = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);
XMFLOAT4 green = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);
XMFLOAT4 blue = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);

Vertex vertices[] =
{
	{ XMFLOAT3(+0.0f, +0.5f, +0.0f), red },
	{ XMFLOAT3(+0.5f, -0.5f, +0.0f), blue },
	{ XMFLOAT3(-0.5f, -0.5f, +0.0f), green },
};

Index indices[] = { 0, 1, 2 };


//Make Buffers
void MakeVertexBuffer() {
	{

		D3D11_BUFFER_DESC vbd = {};
		vbd.Usage = D3D11_USAGE_IMMUTABLE;	// Will NEVER change
		vbd.ByteWidth = sizeof(Vertex) * 3;       // 3 = number of vertices in the buffer
		vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER; // Tells Direct3D this is a vertex buffer
		vbd.CPUAccessFlags = 0;	// Note: We cannot access the data from C++ (this is good)
		vbd.MiscFlags = 0;
		vbd.StructureByteStride = 0;


		D3D11_SUBRESOURCE_DATA initialVertexData = {};
		initialVertexData.pSysMem = vertices; // pSysMem = Pointer to System Memory

		Graphics::Device->CreateBuffer(&vbd, &initialVertexData, vertexBuffer.GetAddressOf());
	}
}

void MakeIndexBuffer() {

	{
		D3D11_BUFFER_DESC ibd = {};
		ibd.Usage = D3D11_USAGE_IMMUTABLE;	// Will NEVER change
		ibd.ByteWidth = sizeof(unsigned int) * 3;	// 3 = number of indices in the buffer
		ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;	// Tells Direct3D this is an index buffer
		ibd.CPUAccessFlags = 0;	// Note: We cannot access the data from C++ (this is good)
		ibd.MiscFlags = 0;
		ibd.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initialIndexData = {};
		initialIndexData.pSysMem = indices; // pSysMem = Pointer to System Memory

		Graphics::Device->CreateBuffer(&ibd, &initialIndexData, indexBuffer.GetAddressOf());
	}
}


int GetVertexCount() {

}

int GetIndexCount() {

}

void Draw() {

}