#include "bone_data_workshop.h"
#include "bone_data.h"
#include "PedPool.h"
#include "global.h"
#include <vector>
#include <functional>
#include <set>



bone_data_workshop::bone_data_workshop(int workernum):m_workernum(workernum),worker_end(false)
{
	
	pthreadpool = new ThreadPool(workernum+1);
	this->workers_queues.resize(workernum);

}
bone_data_workshop::~bone_data_workshop()
{
	if (pthreadpool != nullptr)
	{
		delete pthreadpool;
	}
}
void bone_data_workshop::run()
{
	typedef int32_t ped_handle;	
	//定义任务支配者
	auto task_master = [&]()
	{
		std::vector<ped_handle> native_peds;
		
		while (Hook::end!=true&&worker_end != true)
		{
			native_peds.clear();
			if (GTAIV::pedpool.get_ListofHandle(native_peds) == false)
				continue;
			int task_nums = native_peds.size();

			for (int i = 0; i < task_nums; i++)
			{
				int queue_index = i % m_workernum;
				ped_handle task = native_peds[i];
				this->workers_queues[queue_index].insert(task);
				
			}
		}
	};
	bool _worker_end = this->worker_end;
	bool _hook_end = Hook::end;
	//定义普通工人
	auto common_worker = [&_worker_end,&_hook_end](std::set<ped_handle>& worker_set)
	{
		while (_hook_end && _worker_end != true)
		{
			std::vector<ped_handle> invalid_handles;
			for (const ped_handle& task : worker_set)
			{
				GTAIV::Ped currentPed(task);
				//如果pedhandle 非法那么就将它从work_set删除
				if (task < 0 || currentPed.get_health() < 0)
				{
					invalid_handles.push_back(task);
				}
				int bone_index = task >> 8;


				{
					bone_data* pcurrent_bone_data = new bone_data(bone_index);

					for (int i = 0; i < skeleton_pedbone_data_size; i++)
					{
						pcurrent_bone_data->get_data()[i].from = currentPed.get_bonepositon(skeleton_pedbone_data[i].from);
						pcurrent_bone_data->get_data()[i].to = currentPed.get_bonepositon(skeleton_pedbone_data[i].from);

					}
					//更新bone_data set_bone_data_from_index会将pcurrent_bone_data用来执行移动构造函数所以pcurrent就废弃了
					ESP::sp_bone_data_pool->set_bone_data_from_index(bone_index, std::move(*pcurrent_bone_data));
					
					//怕内存泄露
					if (pcurrent_bone_data->get_data() != nullptr)
					{
						delete pcurrent_bone_data;
					}
					
				}
			}
		}
	};

	
	pthreadpool->enqueue(task_master);

	for (int i = 0; i < this->m_workernum; i++)
	{
		auto& worker_set = this->workers_queues[i];
		pthreadpool->enqueue(common_worker, worker_set);
	}

}