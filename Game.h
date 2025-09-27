#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include <DirectXMath.h>

//Debug Info Struct
struct debug {
	DirectX::XMFLOAT3 bgColor;
	bool DisplayGuiMenu;
};

class Game
{
public:
	// Basic OOP setup
	Game();
	~Game();
	Game(const Game&) = delete; // Remove copy constructor
	Game& operator=(const Game&) = delete; // Remove copy-assignment operator

	//Debug Helper Functions
	debug initializeDebugInfo();
	void UpdateGuiData(float deltaTime, debug guiInfo);
	void BuildUI(debug& guiInfo, int framesElapsed);

	//Main Loop Functions
	void Update(float deltaTime, float totalTime, debug& debugInfo);
	void Draw(float deltaTime, float totalTime, debug& debugInfo);
	void OnResize();

private:

	// Initialization helper methods - feel free to customize, combine, remove, etc.
	void LoadShaders();
	void CreateGeometry();

	// Note the usage of ComPtr below
	//  - This is a smart pointer for objects that abide by the
	//     Component Object Model, which DirectX objects do
	//  - More info here: https://github.com/Microsoft/DirectXTK/wiki/ComPtr

	// Buffers to hold actual geometry data
	Microsoft::WRL::ComPtr<ID3D11Buffer> vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> indexBuffer;

	// Shaders and shader-related constructs
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
};

