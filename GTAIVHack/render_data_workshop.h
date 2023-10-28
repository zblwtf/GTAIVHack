#pragma once
#include "threadpool.h"
#include <set>
#include <vector>
class render_data_workshop
{
public:
	typedef int32_t ped_handle;
	render_data_workshop(int workernum =10);
	~render_data_workshop();
	
	void start_working();
	void GenerateTasks();
	void wait_workshop_finish();
	
private:
	int m_workernum;
	ThreadPool* pthreadpool = nullptr;

	std::vector< std::vector<ped_handle>> workers_tasks;
};