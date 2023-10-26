#include "MouseHook.h"
#include "global.h"
#include <functional>
#include <thread>

HHOOK hhook = NULL;

typedef  LRESULT(__stdcall* wndproc)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
wndproc pwndproc = nullptr;


LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	
	if (nCode < HC_ACTION) {
		return CallNextHookEx(hhook, nCode, wParam, lParam);
	}
	

	if (Menu::m_menuIsOpen)
	{
		switch (wParam)
		{
		case WM_MOUSEWHEEL:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, mouse_message.mouseData, messagelParam);
			}
		}
		case WM_LBUTTONDOWN:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, MK_LBUTTON, messagelParam);
			}
			break;
		}
		case WM_LBUTTONUP:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, 0, messagelParam);
			}
			break;
		}
		case WM_MOUSEMOVE:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, 0, messagelParam);
			}
			break;
		}
		
		case WM_RBUTTONDOWN:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, 0, messagelParam);
			}
			break;
		}
		case WM_RBUTTONUP:
		{
			if (lParam) {
				MSLLHOOKSTRUCT mouse_message = *(MSLLHOOKSTRUCT*)lParam;
				auto mouse_x = mouse_message.pt.x;
				auto mouse_y = mouse_message.pt.y;
				LPARAM messagelParam = MAKELPARAM(mouse_x, mouse_y);
				PostMessageW(window::m_hwindow, wParam, 0, messagelParam);
			}
			break;
		}
		}
	}

	if (pwndproc) {
		
		//pwndproc(window::m_hwindow, nCode, wParam, lParam);
	}
	

	return CallNextHookEx(hhook, nCode, wParam, lParam);
}

MouseHook::MouseHook(wndproc pfn):end(false)
{
	
	pwndproc = pfn;
	hhook = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, GetModuleHandle(NULL), 0);
	if (hhook == NULL) {
		logstream << "[-] MouseHook Create Faild\n";
		logstream.flush();
	}
	else {
		logstream << "[+] MouseHook Create Success\n";
		logstream.flush();
	}
	this->m_hook = hhook;



}
MouseHook::~MouseHook()
{
	pwndproc = nullptr;
	this->end = true;

	if (this->m_hook) {
		BOOL result = UnhookWindowsHookEx(this->m_hook);
		if (!result) {
			logstream << "[-] Remove MouseHook Failed\n";
			logstream.flush();
		}
		else {
			logstream << "[+] Remove MouseHook Success\n";
			logstream.flush();
		}
	}
	hhook = NULL;

}

void MouseHook::set_wndproc(wndproc pfn)
{
	pwndproc = pfn;
}

void  MouseHook::push_msg()
{
	MSG msg;
	// 主消息循环:
	while (!this->end)
	{
		PeekMessage(&msg, nullptr, 0, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		Sleep(2);
	}
}