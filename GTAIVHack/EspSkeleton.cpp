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
#include "render_data.h"
#include "functions.h"
#include "ESP_Render.h"
extern std::fstream logstream;



using namespace GTAIV;
using namespace ESP;












void EspSkeleton::draw_skeletion(render_data* pbone_data)
{
	

	
	std::shared_ptr<bone_t> sp_bone = pbone_data->get_data();
	ESP_Render::Render(pbone_data);

	
	
	 
}
void EspSkeleton::skelete_esp()
{
	

	typedef int32_t pedhandle;
	std::vector<pedhandle> nativehandles;
	ESP_Render::StoreOriginStuff();
	ESP_Render::SetupMatrices();

	GTAIV::pedpool.get_ListofHandle(nativehandles);
	
	auto start = std::chrono::high_resolution_clock::now();
	ESP::sp_myworkshop->wait_workshop_finish();

	for (pedhandle _pedhandle : nativehandles)
	{
		int pedindex = _pedhandle >> 8;
		if (pedindex < 0 || pedindex == 0) 
			continue;
		render_data* _bone_data = ESP::sp_bone_data_pool->read_bone_data_from_index(pedindex);
		if (_bone_data == nullptr)
			continue;
		draw_skeletion(_bone_data);

	}

	auto end = std::chrono::high_resolution_clock::now();
	
	
	
	
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	
	char sp_buf[125]{0};

	
	ImDrawList* m_pdrawlist = ImGui::GetBackgroundDrawList();
	sprintf_s(sp_buf, sizeof(sp_buf), "time%d", (int)duration.count());
	m_pdrawlist->AddText({ 500,50 }, ImColor(255, 0, 0, 255), sp_buf);
	

	ESP_Render::RestoreOriginStuff();
}




