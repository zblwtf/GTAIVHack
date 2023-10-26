#pragma once
#include <stdint.h>
#include <vector>
namespace GTAIV
{
	class PedPool
	{
	public:
		PedPool();
		bool get_pPedfromHandle(int32_t handle,uintptr_t*);
		bool get_pPedfromIndex(int index,uintptr_t*);
		bool get_ListofHandle(std::vector<int32_t>&);
		inline uintptr_t get_pPedList() { return *(uintptr_t*)(m_ppedpool); };
		inline uintptr_t get_pboolList() { return *(uintptr_t*)(m_ppedpool + 0x4); }
		inline int get_maxcount() { return *(int*)(m_ppedpool+0x8); }
		inline int get_itemsize() { return *(int*)(m_ppedpool + 12); }
		
	private:
		uintptr_t m_ppedpool;
	};
}
