#include "ScriptHook/Services/D3DHook.h"
#include "ScriptHook/ScriptHookManager.h"
#include "Hook.h"
#include "global.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "Menu.h"
#include "MouseHook.h"
#include "EspSkeleton.h"


using namespace Hook;
d3d9Hook* m_d3d9Hook = nullptr;

d3d9Hook::d3d9Hook() :m_d3d9override(new d3d9override()) {}



extern LRESULT  ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

void Hook::clean_hook()
{
	

	if (Hook::m_pMouseHook) {
		Hook::m_pMouseHook->set_end(true);
	}
	ESP::sp_myworkshop->stop();

	if (window::m_oldproc) {
		SetWindowLongPtr(window::m_hwindow, GWL_WNDPROC, (LONG_PTR)window::m_oldproc);
	}

	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	/*if (NativeCall::ctx3) {
		delete NativeCall::ctx3;
		NativeCall::ctx3 = nullptr;
	}*/


	m_d3d9Hook->remove_d3d9hook();

	if (m_d3d9Hook != nullptr)
	{
		delete m_d3d9Hook;
		m_d3d9Hook = nullptr;
	}

	

	logstream << "[+]Invoke remove_d3d9Hook\n";
	logstream.flush();

	

}


void  d3d9override::OnRender(ID3DDevice* pDevice)
{
	if (Hook::end) {

		if (NativeCall::ctx3) {
			delete NativeCall::ctx3;
			NativeCall::ctx3 = nullptr;
		}
		return;
	}



	if (d3d9::m_d3d9Device != pDevice) {
		d3d9::m_d3d9Device = pDevice;
	}
	if (!d3d9::d3d9hookinited) {
		pDevice->GetViewport(&d3d9::m_viewport);
		D3DDEVICE_CREATION_PARAMETERS CP;
		pDevice->GetCreationParameters(&CP);
		window::m_hwindow = CP.hFocusWindow;

		logstream << "[+] GTAIV window_handle:\t" << window::m_hwindow << "\n";
		logstream.flush();

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.IniFilename = NULL;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		ESP::sp_myworkshop->run();

		ImGui::StyleColorsDark();
		io.Fonts->AddFontDefault();

		ImGui_ImplWin32_Init(window::m_hwindow);
		ImGui_ImplDX9_Init(pDevice);

		window::m_oldproc = (WNDPROC)GetWindowLongPtr(window::m_hwindow, GWL_WNDPROC);
		SetWindowLongPtr(window::m_hwindow, GWL_WNDPROC, (LONG_PTR)WndProc);


		if (Hook::m_pMouseHook) {
			Hook::m_pMouseHook->set_wndproc(WndProc);
		}
		else {
			logstream << "[-] Hook::m_pMouseHook is Null\n";
			logstream.flush();
		}





		logstream << "[+] d3d9hookinited\n";
		logstream.flush();
		d3d9::d3d9hookinited = true;
	}
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	Menu::show_menu();

	ESP::EspSkeleton::skelete_esp();

	ImGui::EndFrame();
	
	
	


	ImGui::Render();
	ImGui::GetIO().MouseDrawCursor = Menu::menuIsOpen();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

}








LRESULT __stdcall Hook::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    
	


	if (uMsg == WM_KEYDOWN) {
		if (wParam == VK_INSERT) {
			Menu::tmpMenuIsOpen = !Menu::tmpMenuIsOpen;
		}
		if (wParam == VK_END) {
			end = true;
		}
	}
	if (d3d9::d3d9hookinited) {
		if (Menu::menuIsOpen() && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam)) {
			return true;
		}
		
	}
	else
		return CallWindowProc(window::m_oldproc, hWnd, uMsg, wParam, lParam);
	
}






d3d9Hook::~d3d9Hook()
{
	if (m_d3d9override)
	{
		delete m_d3d9override;
	}
}
void Hook::install_hook()
{
	m_d3d9Hook = new d3d9Hook();
	m_d3d9Hook->install_d3d9hook();
	logstream << "[+]Invoke install_d3d9Hook\n";
	logstream.flush();
}



void d3d9Hook::install_d3d9hook()
{
	ID3DHookService* pService = ScriptHookManager::RequestService<ID3DHookService>("D3DHook");
	pService->AddDeviceHook((ID3DDeviceHook*)m_d3d9override);
}
void d3d9Hook::remove_d3d9hook()
{
	ID3DHookService* pService = ScriptHookManager::RequestService<ID3DHookService>("D3DHook");
	pService->RemoveDeviceHook((ID3DDeviceHook*)m_d3d9override);
}

void d3d9override::OnCreateDevice(ID3DDevice* pDevice, PresentParameters* cPresentParameters)
{
	pDevice->GetViewport(&d3d9::m_viewport);
}

void d3d9override::OnResetDevice(ID3DDevice* pDevice, PresentParameters* cPresentParameters)
{
	if (d3d9::m_d3d9Device != pDevice) {
		d3d9::m_d3d9Device = pDevice;

	}
	pDevice->GetViewport(&d3d9::m_viewport);
}
void d3d9override::OnLostDevice(ID3DDevice* pDevice)
{
}
