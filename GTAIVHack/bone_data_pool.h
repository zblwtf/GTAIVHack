#pragma once
#include <cstdint>
#include "bone_data.h"
class bone_data_pool
{
public:
	bone_data_pool();
	~bone_data_pool();
	const bone_data& read_bone_data_from_index(int index) const;
	void set_bone_data_from_index(int index, bone_data&& data);
private:
	bone_data* m_object = nullptr;
	int32_t m_cout = 0;
};