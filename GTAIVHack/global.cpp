#include <d3d9.h>
#include <fstream>
#include "NativeContext3.h"
#include "MouseHook.h"
#include <memory>
#include "Ped.h"
#include "PedPool.h"
#include "bone_data_pool.h"
#include "bone_data_workshop.h"

std::string logpath = R"(C:/Users/23035/Desktop/log.txt)";
std::fstream logstream(logpath, std::ios::app);
uintptr_t module_base = NULL;


namespace d3d9
{
	IDirect3DDevice9* m_d3d9Device = nullptr;
	D3DVIEWPORT9 m_viewport;
	bool d3d9hookinited = false;
}
namespace NativeCall
{
	using fnGetNativeAddress = void* (*)(const char*);
	fnGetNativeAddress pGetNativeAddress = nullptr;
	NativeContext3* ctx3 = new NativeContext3();
}
namespace Menu
{
	float m_traceThick = 0.1f;
	bool tmpMenuIsOpen = false;
	bool m_menuIsOpen = false;
	float m_traceColor[4]{255,255,255,125};
	bool b_renderTraceLine = false;
	float skeleton_scale[3]{ 1.0f,1.0f,1.0f };
	int m_active_ped_count = 0;
}
namespace window
{
	HWND m_hwindow = NULL;;
	WNDPROC m_oldproc = nullptr;
}
namespace Hook
{
	bool end = false;
	typedef  LRESULT(__stdcall* wndproc)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	wndproc pwndproc = nullptr;
	MouseHook* m_pMouseHook = nullptr;
}

namespace ESP
{
	std::shared_ptr<bone_data_pool> sp_bone_data_pool = nullptr;
	std::shared_ptr <bone_data_workshop> sp_myworkshop = nullptr;
}


namespace GTAIV
{
	PedPool pedpool;
}

