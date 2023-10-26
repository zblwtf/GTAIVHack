#include "global.h"
#include "PedPool.h"
#include "offset.h"
using namespace GTAIV;
PedPool::PedPool()
{	
	module_base = (uintptr_t)GetModuleHandleA(NULL);
	this->m_ppedpool = *(uintptr_t*)(module_base + offset::m_pedpool);
	
}
bool PedPool::get_pPedfromIndex(int index,uintptr_t* m_pped)
{
	if (index < 0) {
		return false;
	}
	
	
	uintptr_t m_pList = this->get_pPedList();
	if (!m_pList){
		return false;
	}
	
	uintptr_t m_pboolList = this->get_pboolList();

	if (!m_pboolList) {
		return false;
	}

	int maxcount = this->get_maxcount();
	if (maxcount < 0){
		return false;
	}
	
	int itemsize = this->get_itemsize();
	if (itemsize < 0) {
		return false;
	}

	int flag = *(bool*)(m_pboolList + index);
	
	if (flag & 0x80) {
		return false;
	}
		

	*m_pped = (m_pList + index * itemsize);
	return true;
}



bool PedPool::get_pPedfromHandle(int32_t handle, uintptr_t* m_pped)
{
	int index = handle << 8;
	if (index < 0) {
		return false;
	}


	uintptr_t m_pList = this->get_pPedList();
	if (m_pList == NULL) {
		return false;
	}

	uintptr_t m_pboolList = this->get_pboolList();

	if (m_pboolList == NULL) {
		return false;
	}

	int maxcount = this->get_maxcount();
	if (maxcount < 0) {
		return false;
	}

	int itemsize = this->get_itemsize();
	if (itemsize < 0) {
		return false;
	}

	int flag = *(bool*)(m_pboolList + index);

	if ( flag & 0x80) {
		return false;
	}


	*m_pped = (m_pList + index * itemsize);
	return true;
}



bool PedPool::get_ListofHandle(std::vector<int32_t>& m_pedlist)
{
	
	m_pedlist.clear();

	uintptr_t m_pList = this->get_pPedList();

	
	if (m_pList == NULL) {
		logstream << "[-] m_pList == NULL\n";
		logstream.flush();
		return false;
	}
	uintptr_t m_pboolList = this->get_pboolList();
	
	if (m_pboolList == NULL) {
		logstream << "[-] m_pboolList == NULL\n";
		logstream.flush();
		return false;
	}

	

	int maxcount = this->get_maxcount();
	//初始化vector的容量
	m_pedlist.resize(maxcount);
	m_pedlist.clear();

	if (maxcount < 0) {
		logstream << "[-] maxcount == 0\n";
		logstream.flush();
		return false;
	}
	

	int itemsize = this->get_itemsize();

	if (itemsize < 0) {
		logstream << "[-] item == 0\n";
		logstream.flush();
		return false;
	}

	int32_t val = 0;
	for (int i = 0; i < maxcount; i++) {
		val = (int) * (bool*)(m_pboolList + i); // parity value
		if ((val & 0x80) == 0) { // wrong was: (val > 0)
			val = (i << 8) | val;
			m_pedlist.push_back(val);
		}
	}
	Menu::m_active_ped_count = m_pedlist.size();

	return true;
	
}