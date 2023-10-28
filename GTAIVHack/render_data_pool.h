#pragma once
#include <cstdint>
#include "render_data.h"
class bone_data_pool
{
public:
	bone_data_pool();
	~bone_data_pool();
	render_data* read_bone_data_from_index(int index);
	void set_bone_data_from_index(int index, render_data&& data);
private:
	render_data* m_object = nullptr;
	int32_t m_cout = 0;
};