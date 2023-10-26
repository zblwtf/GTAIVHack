#include "menu.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include "global.h"
#include <memory>
#include <string>
#include "Camera.h"
using namespace Menu;
void Menu::show_menu()
{
#pragma region initmenu
	
#pragma endregion

	updateMenuState();

	


	if (Menu::menuIsOpen())
	{
		bool static inited = false;
		if (!inited)
		{
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize({ 500,300 });
			inited = true;
		}
		
		ImGui::Begin("GTA:IV", &tmpMenuIsOpen,
			ImGuiWindowFlags_NoScrollbar |
			ImGuiWindowFlags_NoScrollWithMouse |
			ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoSavedSettings |
			ImGuiWindowFlags_NoResize);
		ImGui::Columns(2);
		//ImGui::SetColumnOffset(1, 250);
		ImGui::Text("TraceLine");
		
		ImGui::Checkbox("trace_line", &Menu::b_renderTraceLine);
		
		int health_niko = 0;
		vec3 pos_niko{ 0 };
		GTAIV::Ped pedniko(0);
		
		if (GTAIV::get_localplayer(&pedniko))
		{
			
			pos_niko = pedniko.get_bonepositon(GTAIV::head);
			ImGui::Text("bone_position: x:%0.2f\ty:%0.2f\tz:%0.2f", pos_niko.x, pos_niko.y, pos_niko.z);

		}
		 
		

		
		
		Camera gameCamera;
		D3DXVECTOR3 camera_rotation;
		D3DXVECTOR3 camera_positon;
		gameCamera.get_positon(camera_positon);
		gameCamera.get_rotation(camera_rotation);

		ImGui::Text("nativeped_number:%d", Menu::m_active_ped_count);
		

		
		ImGui::Text("camera_position: x:%0.2f\ty:%0.2f\tz:%0.2f", camera_positon.x, camera_positon.y, camera_positon.z);
		ImGui::Text("camera_rotation: pitch:%0.2f\tyaw:%0.2f\troll:%0.2f", camera_rotation.x, camera_rotation.y, camera_rotation.z);
		
		
		ImGui::ColorEdit4("Color:", m_traceColor);
		ImGui::SliderFloat("Thick", &m_traceThick, 0.1f, 1.0f);
		ImGui::SliderFloat3("scale", Menu::skeleton_scale, 1.0f, 2.0f);
		
		ImGui::End();
	}
	



	

}
void Menu::updateMenuState() {

	if (tmpMenuIsOpen != m_menuIsOpen) {
		m_menuIsOpen = tmpMenuIsOpen;
	}
}
bool Menu::menuIsOpen() {
	return m_menuIsOpen;
}
