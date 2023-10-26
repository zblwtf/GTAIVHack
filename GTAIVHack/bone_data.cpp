#include "bone_data.h"
#include <cstdlib>
#include <string>
un_de skeleton_pedbone_data[] = { {Root,����},{����,����},{����,����1},{����1,����2},{����2,����3},{����3,����},{����,head},{����3,������},{������,���ϱ�},{���ϱ�,��ǰ��},{��ǰ��,����},{����3,������},{������,���ϱ�},{���ϱ�,��ǰ��},{��ǰ��,����},{����,�����},{�����,��С��},{��С��,���} ,{���,���ֺ},{����,�Ҵ���},{�Ҵ���,��С��},{��С��,�ҽ�} ,{�ҽ�,�ҽ�ֺ} };


bone_data::bone_data(ped_index pedhandle):m_pedindex(pedhandle)
{
	this->data = new bone_t[skeleton_pedbone_data_size];
	memset(data, 0, sizeof(bone_t) * skeleton_pedbone_data_size);
}
bone_data::bone_data(const bone_data& value):m_pedindex(value.m_pedindex)
{
	this->data = new bone_t[skeleton_pedbone_data_size];
	memcpy(this->data, value.data, sizeof(bone_t) * skeleton_pedbone_data_size);
}
void bone_data::operator=(const bone_data& value)
{
	this->m_pedindex = value.m_pedindex;
	this->data = new bone_t[skeleton_pedbone_data_size];
	memcpy(this->data, value.data, sizeof(bone_t) * skeleton_pedbone_data_size);
}
void bone_data::operator=(bone_data&& rvalue)
{
	this->m_pedindex = rvalue.get_index();
	this->data = rvalue.data;
	rvalue.data = nullptr;
}
bone_data::bone_data(bone_data&& rvalue):m_pedindex(rvalue.m_pedindex)
{	
	
	this->data = rvalue.data;
	rvalue.data = nullptr;
}
bone_data::~bone_data()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

