#include <d3dx9.h>
#include <d3dx9math.h>
#include <d3d9.h>
#include "render_data.h"
#include "ESP_Render.h"
#include <strsafe.h>
#include "global.h"
#include <vector>
#include "MyCamera.h"
#include "MyTransform.h"
using namespace d3d9;

struct CUSTOMVERTEX
{
    float x,y,z;      // The untransformed, 3D position for the vertex
    DWORD color;        // The vertex color
};
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE)
LPDIRECT3DVERTEXBUFFER9 pVertexBuffer = nullptr;
std::vector<CUSTOMVERTEX> VerticesVector;
std::vector<D3DXVECTOR2> LinesVector;
DWORD trace_color;
DWORD rect_color;
DWORD skeleton_color;
ID3DXLine* LineL = nullptr;


#pragma region storeobject
D3DXMATRIX oriProjectMatrix;
D3DXMATRIX oriWorldMatrix;
D3DVIEWPORT9 oriViewPort;
DWORD dwrender_state_lighting;
#pragma endregion


HRESULT ESP_Render::InitGeometry()
{

    if (LineL == nullptr)
    {
        if (D3DXCreateLine(m_d3d9Device, &LineL) != S_OK)
            return E_FAIL;
    }

    int line_numer = skeleton_pedbone_data_size;

    if (FAILED(d3d9::m_d3d9Device->CreateVertexBuffer( 2*line_numer* sizeof(CUSTOMVERTEX),
        D3DUSAGE_DYNAMIC, D3DFVF_CUSTOMVERTEX,
        D3DPOOL_DEFAULT, &pVertexBuffer, NULL)))
    {
       
        return E_FAIL;
    }
    VerticesVector.resize(2 * line_numer );
    LinesVector.resize(2 * cube_data_size);
    return S_OK;

}
HRESULT ESP_Render::UpdateGeometry(render_data* p_bonedata)
{
    VerticesVector.clear();
    LinesVector.clear();
    if (p_bonedata->update() == false)
    {
        return S_OK;
    }
    auto sp_data = p_bonedata->get_data();
    auto sp_cubedata = p_bonedata->get_cube_data();

#pragma region getcolor
    

    int skeleton_alp = (int)(Menu::m_skeletonColor[3] * 255);
    int skeleton_r = (int)(Menu::m_skeletonColor[0] * 255);
    int skeleton_g = int(Menu::m_skeletonColor[1] * 255);
    int skeleton_b = int(Menu::m_skeletonColor[2] * 255);
    int trace_alp = (int)(Menu::m_traceColor[3] * 255);
    int trace_r = (int)(Menu::m_traceColor[0] * 255);
    int trace_g = int(Menu::m_traceColor[1] * 255);
    int trace_b = int(Menu::m_traceColor[2] * 255);
    int rect_alp = (int)(Menu::m_cubeColor[3] * 255);
    int rect_r = (int)(Menu::m_cubeColor[0] * 255);
    int rect_g = int(Menu::m_cubeColor[1] * 255);
    int rect_b = int(Menu::m_cubeColor[2] * 255);

    trace_color = D3DCOLOR_ARGB(trace_alp, trace_r, trace_g, trace_b);
    rect_color = D3DCOLOR_ARGB(rect_alp, rect_r, rect_g, rect_b);
    
   
    skeleton_color = D3DCOLOR_ARGB(skeleton_alp, skeleton_r, skeleton_g, skeleton_b);
    

#pragma endregion



    

    if (Menu::b_renderSkeleton)
    {
        for (int i = 0; i < skeleton_pedbone_data_size; i++)
        {

            vec3 from_pos = sp_data.get()[i].from;
            vec3 to_pos = sp_data.get()[i].to;
            VerticesVector.push_back({ from_pos.x,from_pos.z,from_pos.y ,skeleton_color });
            VerticesVector.push_back({ to_pos.x,to_pos.z,to_pos.y,skeleton_color });


        }
    }
    if (Menu::b_renderTraceLine)
    {
        for (int i = 0; i < cube_data_size; i++)
        {


            vec2& screen_pos_from = sp_cubedata.get()[i].from;
            vec2& screen_pos_to = sp_cubedata.get()[i].to;
            LinesVector.push_back({ screen_pos_from.x,screen_pos_from.y });
            LinesVector.push_back({ screen_pos_to.x,screen_pos_to.y });

        }
    }

    if (VerticesVector.empty())
        return S_OK;

    VOID* pVertices;
    if (FAILED(pVertexBuffer->Lock(0, sizeof(CUSTOMVERTEX)*VerticesVector.size(), (void**)&pVertices, 0)))
        return E_FAIL;
    memcpy(pVertices, VerticesVector.data(), sizeof(CUSTOMVERTEX) * VerticesVector.size());
    pVertexBuffer->Unlock();

    return S_OK;
}
void ESP_Render::StoreOriginStuff()
{
    //保留原来的ProjectMatrix
    //g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    
    m_d3d9Device->GetRenderState(D3DRS_LIGHTING, &dwrender_state_lighting);
    
    m_d3d9Device->GetTransform(D3DTS_PROJECTION, &oriProjectMatrix);
    m_d3d9Device->GetTransform(D3DTS_WORLD, &oriWorldMatrix);
}

void ESP_Render::RestoreOriginStuff()
{
    
    m_d3d9Device->SetTransform(D3DTS_PROJECTION, &oriProjectMatrix);
    m_d3d9Device->SetTransform(D3DTS_WORLD, &oriWorldMatrix);
    m_d3d9Device->SetRenderState(D3DRS_LIGHTING, dwrender_state_lighting);
}
void ESP_Render::SetupMatrices()
{
    

    D3DXMATRIX worldMatrix;
    D3DXMatrixIdentity(&worldMatrix);
    m_d3d9Device->SetTransform(D3DTS_WORLD, &worldMatrix);

    ESP::MyCamera my_camera;
    D3DXMATRIX viewMatrix = my_camera.getViewMatrix();
    D3DVIEWPORT9 viewport;
    if (MyTransform::get_viewport(&viewport) == false)
        viewport = d3d9::m_viewport;

    D3DXMATRIX projectMatrix;
    MyTransform::get_projectmatrix(projectMatrix,viewport);

    m_d3d9Device->SetTransform(D3DTS_VIEW, &viewMatrix);

    

    m_d3d9Device->SetTransform(D3DTS_PROJECTION, &projectMatrix);

}
void ESP_Render::Render(render_data* p_bonedata)
{
    if (p_bonedata == nullptr)

        return;

    int line_number = skeleton_pedbone_data_size;
    if (!Menu::b_renderSkeleton && !Menu::b_renderTraceLine)
    {
        return;
    }


    //Update VertexBuffer
    if (UpdateGeometry(p_bonedata) != S_OK)
        return;




    m_d3d9Device->SetRenderState(D3DRS_LIGHTING, FALSE);
    // Render the vertex buffer contents
    //m_d3d9Device->SetRenderState(D3DRS_LINEWIDTH, 2.0f);

    if (Menu::b_renderTraceLine && !LinesVector.empty()) {
        
        LineL->SetWidth(Menu::m_traceThick);
        LineL->Draw(LinesVector.data(), 1 * 2, trace_color);
        LineL->SetWidth(Menu::m_cubeThick);
        LineL->Draw(LinesVector.data() + 2, (cube_data_size - 1) * 2, rect_color);
    }



    
    if (Menu::b_renderSkeleton)
    {
        m_d3d9Device->SetStreamSource(0, pVertexBuffer, 0, sizeof(CUSTOMVERTEX));
        m_d3d9Device->SetFVF(D3DFVF_CUSTOMVERTEX);

        m_d3d9Device->DrawPrimitive(D3DPT_LINELIST, 0, line_number);

    }
}
void ESP_Render::Cleanup()
{
    if (pVertexBuffer != nullptr)
    {
        pVertexBuffer->Release();
    }

    VerticesVector.~vector();
}