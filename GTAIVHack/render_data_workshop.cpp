#include "render_data_workshop.h"
#include "render_data.h"
#include "PedPool.h"
#include "global.h"
#include <vector>
#include <functional>
#include <set>
#include <mutex>
#include <chrono>
#include <memory>
#include <d3dx9.h>
#include <d3dx9math.h>
#include <condition_variable>
#include "MyTransform.h"
std::mutex mtx;
std::condition_variable workshop_cv;
int finish_worker_number = 0;



render_data_workshop::render_data_workshop(int workernum):m_workernum(workernum)
{
	
	pthreadpool = new ThreadPool(workernum);
	this->workers_tasks.resize(workernum);

}
render_data_workshop::~render_data_workshop()
{
	if (pthreadpool != nullptr)
	{
		delete pthreadpool;
	}
}
void render_data_workshop::GenerateTasks()
{
	
	//清空之前的任务
	finish_worker_number = 0;
	for (int i = 0; i < workers_tasks.size(); i++)
	{
		workers_tasks[i].clear();
	}
	

	std::vector<ped_handle> native_peds;
	GTAIV::pedpool.get_ListofHandle(native_peds);
	int task_nums = native_peds.size();
	Menu::m_active_ped_count = task_nums;
	for (int i = 0; i < task_nums; i++)
	{
		ped_handle task = native_peds[i];
		int bone_index = task >> 8;
		uintptr_t ped_address;
		if (pedpool.get_pPedfromIndex(bone_index, &ped_address) == false)
			continue;
		int health = *(float*)(ped_address + 0x214);
		int queue_index = i % m_workernum;
		
		if (task < 0 || health < 10)
			continue;
		workers_tasks[queue_index].push_back(task);
	}

}
void render_data_workshop::start_working()
{
	auto common_worker = [&](std::vector<ped_handle>* worker_tasks)
	{

		if (worker_tasks == nullptr)
		{
			logstream << "[-] worker_set is null\n";
			return;
		}	
		for (auto iterator = worker_tasks->begin(); iterator != worker_tasks->end() && (!Hook::end); iterator++)
		{
			ped_handle task = *iterator;
			if (task < 0)
				continue;

			GTAIV::Ped currentPed(task);
			//如果pedhandle 非法那么就将它从work_set删除
			int bone_index = task >> 8;
			{
				render_data current_bone_data(bone_index);

				std::shared_ptr<bone_t> spdata = current_bone_data.get_data();

				render_data* ppooldata = ESP::sp_bone_data_pool->read_bone_data_from_index(bone_index);


				if (Menu::b_renderSkeleton)
				{
					for (int i = 0; i < skeleton_pedbone_data_size; i++)
					{
						vec3 from;
						vec3 to;
						from = currentPed.get_bonepositon(skeleton_pedbone_data[i].from);

						to = currentPed.get_bonepositon(skeleton_pedbone_data[i].to);
						if (from == vec3{ 0,0,0 } || to == vec3{ 0,0,0 })
						{
							from = ppooldata->get_data().get()[i].from;
							to = ppooldata->get_data().get()[i].to;
						}

						spdata.get()[i].from = from;
						spdata.get()[i].to = to;
					}
				}
				

				if (Menu::b_renderTraceLine)
				{
					vec3 root_pos = currentPed.get_bonepositon(skeleton_pedbone_data[0].from);
					vec3 head_pos = currentPed.get_bonepositon(skeleton_pedbone_data[6].to);
					std::shared_ptr<cube_t> sp_cubedata = current_bone_data.get_cube_data();
					float& root_x = root_pos.x;
					float& root_y = root_pos.y;
					float& root_z = root_pos.z;
					float& head_z = head_pos.z;

					int delta_z = head_z - root_z;
					float width = abs(root_z - head_z) * Menu::m_cubewidth;

					vec3 _side12_from[cube_data_size]{ 0 };
					vec3 _side12_to[cube_data_size]{ 0 };

#pragma region calcposition
					_side12_from[0] = { ESP::niko_pos.x,ESP::niko_pos.z,ESP::niko_pos.y };
					_side12_to[0] = { root_x,root_z,root_y };

					//1
					_side12_from[1] = { root_x - width       ,root_z - width   ,root_y - width };
					_side12_to[1] = { root_x + width         ,root_z - width   ,root_y - width };

					//2
					_side12_from[2] = { root_x + width    ,root_z - width    ,root_y - width };
					_side12_to[2] = { root_x + width     ,root_z - width    ,root_y + width };

					//3
					_side12_from[3] = { root_x - width ,root_z - width    ,root_y + width };
					_side12_to[3] = { root_x + width ,root_z - width    ,root_y + width };

					//4
					_side12_from[4] = { root_x - width ,root_z - width    ,root_y - width };
					_side12_to[4] = { root_x - width ,root_z - width    ,root_y + width };

					//5
					_side12_from[5] = { root_x - width,root_z - width,root_y - width };
					_side12_to[5] = { root_x - width,root_z + width,root_y - width };

					//6
					_side12_from[6] = { root_x + width,root_z - width,root_y - width };
					_side12_to[6] = { root_x + width,root_z + width,root_y - width };

					//7
					_side12_from[7] = { root_x + width,root_z - width,root_y + width };
					_side12_to[7] = { root_x + width,root_z + width,root_y + width };

					//8
					_side12_from[8] = { root_x - width,root_z - width,root_y + width };
					_side12_to[8] = { root_x - width,root_z + width,root_y + width };

					//9
					_side12_from[9] = { root_x - width       ,root_z + width   ,root_y - width };
					_side12_to[9] = { root_x + width         ,root_z + width   ,root_y - width };

					//10
					_side12_from[10] = { root_x + width    ,root_z + width    ,root_y - width };
					_side12_to[10] = { root_x + width     ,root_z + width    ,root_y + width };

					//11
					_side12_from[11] = { root_x - width ,root_z + width    ,root_y + width };
					_side12_to[11] = { root_x + width ,root_z + width    ,root_y + width };

					//12
					_side12_from[12] = { root_x - width ,root_z + width    ,root_y - width };
					_side12_to[12] = { root_x - width ,root_z + width    ,root_y + width };


					
#pragma endregion

#pragma region getscreenpos
					vec2 screenpos_from;
					vec2 screenpos_to;
					for (int i = 0; i < cube_data_size; i++)
					{
						vec3 from_pos = {_side12_from[i].x,_side12_from[i].z, _side12_from[i].y };
						vec3 to_pos = { _side12_to[i].x,_side12_to[i].z, _side12_to[i].y };
						if (MyTransform::WorldToScreen(from_pos, screenpos_from) && MyTransform::WorldToScreen(to_pos, screenpos_to))
						{
							sp_cubedata.get()[i].from = screenpos_from;
							sp_cubedata.get()[i].to = screenpos_to;
						}
					}
#pragma endregion

				}
				else {
					current_bone_data.set_cube_data_null();
				}
				



				if (Menu::b_renderSkeleton || Menu::b_renderTraceLine)
				{
					ESP::sp_bone_data_pool->set_bone_data_from_index(bone_index, std::move(current_bone_data));
				}
				
				
				
				
				//不用怕内存泄露

			}

		}

		//通知任务已经完成
		{
			std::unique_lock<std::mutex> lock(mtx);
			finish_worker_number++;
			
		}
		workshop_cv.notify_one();

	};
	for (int i = 0; i < this->m_workernum; i++)
	{

		pthreadpool->enqueue(std::bind(common_worker, &this->workers_tasks[i]));
	}
}
void render_data_workshop::wait_workshop_finish()
{
	{
		std::unique_lock<std::mutex> lock(mtx);
		// 等待所有任务完成
		workshop_cv.wait(lock, [&] { return finish_worker_number == m_workernum; });
	}
}
