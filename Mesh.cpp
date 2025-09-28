#include "Graphics.h"
#include "Mesh.h"

#include <d3d11.h>
#include <wrl/client.h>
#include <DirectXMath.h>

// For the DirectX Math library
using namespace DirectX;


//Make Buffers
void Mesh::MakeVertexBuffer(Vertex verticies[], int vertCount) {
	{

		D3D11_BUFFER_DESC vbd = {};
		vbd.Usage = D3D11_USAGE_IMMUTABLE;	// Will NEVER change
		vbd.ByteWidth = sizeof(Vertex) * vertCount;
		vbd.BindFlags = D3D11_BIND_VERTEX_BUFFER; // Tells Direct3D this is a vertex buffer
		vbd.CPUAccessFlags = 0;	// Note: We cannot access the data from C++ (this is good)
		vbd.MiscFlags = 0;
		vbd.StructureByteStride = 0;


		D3D11_SUBRESOURCE_DATA initialVertexData = {};
		initialVertexData.pSysMem = verticies; // pSysMem = Pointer to System Memory

		Graphics::Device->CreateBuffer(&vbd, &initialVertexData, vertexBuffer.GetAddressOf());
	}
}

void Mesh::MakeIndexBuffer(Index indicies[], int indxCount) {
	{
		D3D11_BUFFER_DESC ibd = {};
		ibd.Usage = D3D11_USAGE_IMMUTABLE;	// Will NEVER change
		ibd.ByteWidth = sizeof(unsigned int) * indxCount;
		ibd.BindFlags = D3D11_BIND_INDEX_BUFFER;	// Tells Direct3D this is an index buffer
		ibd.CPUAccessFlags = 0;	// Note: We cannot access the data from C++ (this is good)
		ibd.MiscFlags = 0;
		ibd.StructureByteStride = 0;

		D3D11_SUBRESOURCE_DATA initialIndexData = {};
		initialIndexData.pSysMem = indicies; // pSysMem = Pointer to System Memory

		Graphics::Device->CreateBuffer(&ibd, &initialIndexData, indexBuffer.GetAddressOf());
	}
}


int Mesh::GetVertexCount(Vertex vertexes[]) {
	return sizeof(vertexes);
}

int Mesh::GetIndexCount(Index indicies[]) {
	return sizeof(indicies);
}

void Mesh::Draw(int indxCount) {
	{
		UINT stride = sizeof(Vertex);
		UINT offset = 0;
		Graphics::Context->IASetVertexBuffers(0, 1, vertexBuffer.GetAddressOf(), &stride, &offset);
		Graphics::Context->IASetIndexBuffer(indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);


		Graphics::Context->DrawIndexed(
			indxCount,     // The number of indices to use (we could draw a subset if we wanted)
			0,     // Offset to the first index we want to use
			0);    // Offset to add to each index when looking up vertices
	}

}
