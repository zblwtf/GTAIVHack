#pragma once
#include "threadpool.h"
#include <set>
#include <vector>
class bone_data_workshop
{
public:
	typedef int32_t ped_handle;
	bone_data_workshop(int workernum =5);
	~bone_data_workshop();
	void run();
	inline void stop() { this->worker_end = true; }
private:
	int m_workernum;
	ThreadPool* pthreadpool = nullptr;
	bool worker_end = false;
	std::vector< std::set<ped_handle>> workers_queues;
};