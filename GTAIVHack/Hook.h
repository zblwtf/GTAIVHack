#include "ScriptHook/Services/D3DHook.h"
namespace Hook
{
	class d3d9override :ID3DDeviceHook
	{
	private:
		void OnCreateDevice(ID3DDevice* cDevice, PresentParameters* cPresentParameters) override;
		void OnResetDevice(ID3DDevice* cDevice, PresentParameters* cPresentParameters) override;
		void OnLostDevice(ID3DDevice* cDevice)override;
		void OnDestroyDevice(ID3DDevice* cDevice)override { /* nothing to do here */ }
		void OnRender(ID3DDevice* cDevice)override;
	};

	class d3d9Hook
	{
	public:
		d3d9Hook();
		~d3d9Hook();
		void install_d3d9hook();
		void remove_d3d9hook();
	private:
		d3d9override* m_d3d9override = nullptr;
	};
	
	void install_hook();
	void clean_hook();

	LRESULT __stdcall WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}