#pragma once
#include <d3d9.h>
#include <fstream>
#include <string>
#include "NativeContext3.h"
#include "Classess.h"
#include "MouseHook.h"
#include "Ped.h"
#include <memory>
#include "PedPool.h"
#include "render_data_pool.h"
#include <memory>
#include "render_data_workshop.h"
namespace d3d9
{
	extern IDirect3DDevice9* m_d3d9Device;
	extern D3DVIEWPORT9 m_viewport;
	extern bool d3d9hookinited;
}
namespace NativeCall
{
	using fnGetNativeAddress = void* (*)(const char*);
	extern fnGetNativeAddress pGetNativeAddress;
}
namespace Menu
{
	extern float m_traceThick;
	extern float m_cubeThick;
	extern bool tmpMenuIsOpen;
	extern bool m_menuIsOpen;
	extern float m_traceColor[4];
	extern float m_skeletonColor[4];
	extern float m_cubeColor[4];
	extern float m_cubewidth;
	
	extern bool b_renderTraceLine;
	extern bool b_renderSkeleton;
	extern int m_active_ped_count;
	extern float aspectcompensate;
}

namespace ESP
{
	extern std::shared_ptr<bone_data_pool> sp_bone_data_pool;
	extern std::shared_ptr <render_data_workshop> sp_myworkshop;
	extern vec3 niko_pos;
}

namespace window
{
	extern HWND m_hwindow;
	extern WNDPROC m_oldproc;
	extern float width;
	extern float height;

}
namespace Hook
{
	extern bool end;
	typedef  LRESULT(__stdcall* wndproc)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	extern wndproc pwndproc;
	extern MouseHook* m_pMouseHook;
}
namespace GTAIV
{
	extern PedPool pedpool;
}
extern std::fstream logstream;
extern std::string logpath;

extern uintptr_t module_base;

