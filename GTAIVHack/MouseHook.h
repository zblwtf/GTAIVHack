#pragma once
#include <Windows.h>

typedef  LRESULT(__stdcall* wndproc)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
class MouseHook
{
public:
	MouseHook(wndproc pfn=nullptr);
	~MouseHook();
	void  push_msg();
	void set_wndproc(wndproc pfn);
	inline HHOOK get_hook() { return this->m_hook; }
	inline bool get_end() {return this->end; }
	inline void set_end(bool value) { this->end = value; }
private:
	HHOOK m_hook;
	bool end;
};