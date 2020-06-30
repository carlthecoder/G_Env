#include "GraphicsDevice.h"
#include <d3dcompiler.h>
#include <array>

// add the direct3d libraries
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib")

using Microsoft::WRL::ComPtr;

// PUBLIC:
GraphicsDevice::GraphicsDevice()
{
	// A Graphics device is an object that allows us to communicate with the actual graphics chip and control the rendering pipeline

	/* The rendering pipeline:
		- The input assembler stage
			> collects and compiles information from video memory about the 3D models you wish to render (i.e. vertex position etc...)
		- The rasterizer stage
			> determines where on the back buffer images are to be drawn, more specifically: which pixels and what color
		- The output-merger stage
			> combines the individual model images into one whole image, and places that image correctly on the back buffer 
	*/	
}

void GraphicsDevice::Initialize(HWND& hwnd, float width, float height)
{
	CreateDeviceAndContext();
	CreateSwapChain(hwnd, width, height);
	CreateRenderTarget();
	CreateViewPort();

	InitGraphics();
	InitPipeline();
}

void GraphicsDevice::ClearRenderTarget(float r, float g, float b)
{
	_cpContext->OMSetRenderTargets(1, _cpTarget.GetAddressOf(), nullptr);

	float color[4] = { r, g, b, 1.0f };
	_cpContext->ClearRenderTargetView(_cpTarget.Get(), color);
}

void GraphicsDevice::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	_cpContext->IASetVertexBuffers(0, 1, _cpVertexBuffer.GetAddressOf(), &stride, &offset);

	// TESST CODE
	//DrawTriangle();
	
	_cpContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	_cpContext->Draw(3, 0);
}

void GraphicsDevice::PresentFrame()
{
	_cpSwapChain->Present(1, 0);
}

void GraphicsDevice::CleanD3D()
{
	_cpSwapChain->SetFullscreenState(FALSE, NULL);    // switch to windowed mode	
}

// PRIVATE:
void GraphicsDevice::CreateDeviceAndContext()
{
	HRESULT hr;
	if (FAILED(hr = D3D11CreateDevice(
		nullptr,
		D3D_DRIVER_TYPE_HARDWARE,
		nullptr,
		0,
		nullptr,
		0,
		D3D11_SDK_VERSION,
		&_cpDevice,
		nullptr,
		&_cpContext)))
	{
		throw GraphicsException(__LINE__, __FILE__, hr);
	}

	// The device and the context are 2 sides of the same coin. 
	// They both represent the graphics device.
	// However, the device is used for resource creation and management
	// while the context is used for the actual rendering.
}

void GraphicsDevice::CreateSwapChain(HWND& hwnd, float width, float height)
{
	ComPtr<IDXGIDevice> dxgiDevice;
	_cpDevice.As(&dxgiDevice);

	ComPtr<IDXGIAdapter> dxgiAdapter;
	dxgiDevice->GetAdapter(&dxgiAdapter);

	ComPtr<IDXGIFactory> dxgiFactory;
	dxgiAdapter->GetParent(__uuidof(IDXGIFactory), &dxgiFactory);

	DXGI_SWAP_CHAIN_DESC scd;
	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));

	scd.BufferCount = 2;
	scd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	scd.BufferDesc.Width = static_cast<unsigned int>(width);
	scd.BufferDesc.Height = static_cast<unsigned int>(height);
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = hwnd;
	scd.SampleDesc.Count = 4;
	scd.Windowed = true;
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	
	HRESULT hr;
	if (FAILED(hr = dxgiFactory->CreateSwapChain(
		_cpDevice.Get(),
		&scd,
		&_cpSwapChain)))
	{
		throw GraphicsException(__LINE__, __FILE__, hr);
	}

	// note:
	// A swap chain is a chain of (texture) buffers that are swapped to the front buffer at a regular interval to minimzize tearing.
	// by making sure only completely drawn images are shown on the screen.
	// turn our device into and idxgi device

	// How to:
	// cast device as IDGI device
	// get adapter from device
	// get factory through adapter parent
	// create the descriptor for swap chain 
	// create the swap chain from the descriptor
}

void GraphicsDevice::CreateRenderTarget()
{
	ComPtr<ID3D11Texture2D> backbuffer;
	_cpSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backbuffer);
	_cpDevice->CreateRenderTargetView(backbuffer.Get(), nullptr, &_cpTarget);
	_cpContext->OMSetRenderTargets(1, _cpTarget.GetAddressOf(), nullptr);

	// A render target is a com object that holds a location in video memory to render into. 
	// In most cases the render target is the back buffer
	// - Get the address of the backbuffer;
	// - Create the render target from the backbuffer
	// - Set the render target as the backbuffer	
}

void GraphicsDevice::CreateViewPort()
{
	D3D11_VIEWPORT viewport;
	ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = 800;
	viewport.Height = 600;

	_cpContext->RSSetViewports(1, &viewport);

	// A viewport is a way of translating pixel coordinates to normalized coordinates.
}

void GraphicsDevice::InitPipeline()
{
	ComPtr<ID3DBlob> shaderBlob;	

	D3DReadFileToBlob(L"PixelShader.cso", &shaderBlob);	
	_cpDevice->CreatePixelShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &_pixelShader);
	_cpContext->PSSetShader(_pixelShader.Get(), nullptr, 0u);

	D3DReadFileToBlob(L"VertexShader.cso", &shaderBlob);	
	_cpDevice->CreateVertexShader(shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), nullptr, &_vertexShader);
	_cpContext->VSSetShader(_vertexShader.Get(), nullptr, 0u);	

	// For the pipeline to work we need to load at least a vertex and a pixel shader
	// - Create ID3DBlob
	// - Read shader file into Blob
	// - Create shader com object
	// - Use device to create shader from the blob and store it into the shader obhect
	// - Use context to set shader to active shader
	
	// Create InputLayout
	D3D11_INPUT_ELEMENT_DESC ied[] =
	{
		{"Position", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"Color", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};
	
	_cpDevice->CreateInputLayout(ied, (UINT)std::size(ied), shaderBlob->GetBufferPointer(), shaderBlob->GetBufferSize(), &_cpInputLayout);
	_cpContext->IASetInputLayout(_cpInputLayout.Get());
}

void GraphicsDevice::InitGraphics()
{	
	CreateTriangle();

	// The vertexbuffer is the bridge to the videomemory and is what allows the cpu to transfer the vertex data.
	// - Create a vertex buffer descriptor, specifying the usage, the size of the vertices to be drawn, the size of a single vertex, and the bind flags.
	// - Create a vertex buffer com object, and use the device to fill it by creating the buffer from the descriptor inside of it.	
}

void GraphicsDevice::CreateTriangle()
{
	Vertex vertices[]
	{
		{ Position {0.0f,0.5f,0.0f}, Color{1,0,0,0 } },
		{ Position {0.5f, -0.5f, 0.0f}, Color {0, 1, 0, 0} },
		{ Position {-0.5f, -0.5f, 0.0f}, Color {0, 0, 1, 0} }
	};

	D3D11_BUFFER_DESC bufferDescriptor = {};
	bufferDescriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDescriptor.ByteWidth = sizeof(vertices);
	bufferDescriptor.StructureByteStride = sizeof(Vertex);
	bufferDescriptor.CPUAccessFlags = 0u;
	bufferDescriptor.MiscFlags = 0u;
	bufferDescriptor.Usage = D3D11_USAGE_DEFAULT;

	D3D11_SUBRESOURCE_DATA resourceData = {};
	resourceData.pSysMem = vertices;

	_cpDevice->CreateBuffer(&bufferDescriptor, &resourceData, &_cpVertexBuffer);
}