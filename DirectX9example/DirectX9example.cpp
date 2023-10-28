#include <Windows.h>
#include <d3d9.h>
#include <strsafe.h>
// 定义顶点结构体
struct CUSTOMVERTEX {
    FLOAT x, y, z;
    DWORD color;
};
HWND hWnd;

// 程序入口点
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 创建窗口等初始化步骤省略...

    // 初始化Direct3D
    LPDIRECT3D9 d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
    if (!d3d9) {
        // 错误处理
        return 1;
    }

    // 创建Direct3D设备
    LPDIRECT3DDEVICE9 device;
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    if (FAILED(d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &device)))
    {
        // 错误处理
        return 1;
    }

    // 定义顶点数据
    const int NUM_VERTICES = 4;
    CUSTOMVERTEX vertices[NUM_VERTICES] = {
        {100.0f, 100.0f, 0.0f, D3DCOLOR_XRGB(255, 0, 0)},   // 红色
        {200.0f, 100.0f, 0.0f, D3DCOLOR_XRGB(0, 255, 0)},   // 绿色
        {100.0f, 200.0f, 0.0f, D3DCOLOR_XRGB(0, 0, 255)},   // 蓝色
        {200.0f, 200.0f, 0.0f, D3DCOLOR_XRGB(255, 255, 0)}  // 黄色
    };

    // 创建顶点缓冲区
    LPDIRECT3DVERTEXBUFFER9 vertexBuffer;
    if (FAILED(device->CreateVertexBuffer(NUM_VERTICES * sizeof(CUSTOMVERTEX),
        0, D3DFVF_XYZ | D3DFVF_DIFFUSE, D3DPOOL_DEFAULT, &vertexBuffer, NULL)))
    {
        // 错误处理
        return 1;
    }

    // 锁定顶点缓冲区，并填充顶点数据
    VOID* pVertices;
    if (FAILED(vertexBuffer->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
    {
        // 错误处理
        return 1;
    }
    memcpy(pVertices, vertices, sizeof(vertices));
    vertexBuffer->Unlock();

    // 清除渲染目标
    device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

    // 开始绘制
    if (SUCCEEDED(device->BeginScene())) {
        device->SetStreamSource(0, vertexBuffer, 0, sizeof(CUSTOMVERTEX));
        device->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
        device->DrawPrimitive(D3DPT_LINELIST, 0, NUM_VERTICES / 2);

        device->EndScene();
    }

    // 切换显示缓冲区
    device->Present(NULL, NULL, NULL, NULL);

    // 释放资源
    vertexBuffer->Release();
    device->Release();
    d3d9->Release();

    // 窗口销毁等处理省略...

    return 0;
}
