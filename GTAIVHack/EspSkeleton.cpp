#include "Classess.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "EspSkeleton.h"
#include "Ped.h"
#include "MyTransform.h"
#include <fstream>
#include <cstring>
#include "Camera.h"
#include "global.h"
#include <ctime>
#include <chrono>
#include "PedPool.h"
#include <vector>
#include "bone_data.h"
extern std::fstream logstream;



using namespace GTAIV;
using namespace ESP;
void EspSkeleton::draw_skeletion(Ped ped)
{
	ImDrawList* m_pdrawlist = ImGui::GetBackgroundDrawList();
		

	
	
	
	vec3 pedroot = ped.get_bonepositon(Root);
	vec3 pedpos = ped.get_position();

	//MyTransform::print_matrix(project_matrix);
	/*char sprtf_buf[256]{ 0 };
	sprintf_s(sprtf_buf, sizeof(sprtf_buf), "[+] bonepositon:x:%0.2f\ty:%0.2f\tz:%0.2f\n", bone_positon.x, bone_positon.y, bone_positon.z);
	logstream << sprtf_buf;
	logstream.flush();*/
	vec2 screen_position_from{ 0 };
	vec2 screen_position_to{ 0 };
	vec3 bone_positon_from{ 0 };
	vec3 bone_positon_to{ 0 };
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < skeleton_pedbone_data_size; i++)
	{
		

		bone_positon_from = ped.get_bonepositon(skeleton_pedbone_data[i].from);
		

		bone_positon_to = ped.get_bonepositon(skeleton_pedbone_data[i].to);
		

		if (MyTransform::WorldToScreen(bone_positon_from, screen_position_from)&& MyTransform::WorldToScreen(bone_positon_to, screen_position_to))
		{
			m_pdrawlist->AddLine(screen_position_from, screen_position_to, ImColor(255, 255, 255, 255), 10);
	
		}
	}  

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	logstream << "time:" << duration.count()<< std::endl;
	logstream.flush();
}
void EspSkeleton::skelete_esp()
{
	/*typedef int32_t ped_handle;
	std::vector<ped_handle> ped_handle_pool;

	if (GTAIV::pedpool.get_ListofHandle(ped_handle_pool) == false) {
		logstream << "[-] get ped pool failed\n";
		logstream.flush();
		return;
	}*/
	
	
	//for (int i = 0; i < 2; i++)
	//{
	//	
	//	ped_handle current_ped_handle = ped_handle_pool[i];
	//	Ped ped(current_ped_handle);
	//	logstream << "ped health:" << ped.get_health() << std::endl;

	//	//draw_skeletion(ped);
	//}
	//logstream.flush();
}