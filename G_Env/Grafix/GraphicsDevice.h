#pragma once
#include <d3d11.h>
#include <wrl.h>
#include "GraphicsException.h"
#include "Vertex.h"

class GraphicsDevice sealed
{
	public:
		GraphicsDevice();
		~GraphicsDevice() = default;
		GraphicsDevice(const GraphicsDevice&) = delete;
		GraphicsDevice& operator=(const GraphicsDevice&) = delete;
		
		void Initialize(HWND& hwnd, float width, float height);
		void ClearRenderTarget(float r, float g, float b);
		void Render();
		void PresentFrame();
		void CleanD3D();

	private:
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> _cpContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain> _cpSwapChain;
		Microsoft::WRL::ComPtr<ID3D11Device> _cpDevice;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _cpTarget;
		Microsoft::WRL::ComPtr<ID3D11Buffer> _cpVertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11PixelShader> _pixelShader	;
		Microsoft::WRL::ComPtr<ID3D11VertexShader> _vertexShader;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> _cpInputLayout;
		
		void CreateDeviceAndContext();
		void CreateSwapChain(HWND& hwnd, float width, float height);
		void CreateRenderTarget();
		void CreateViewPort();
		void InitPipeline();
		void InitGraphics();
		void CreateTriangle();
};