#pragma once
#include <cstdint>
#include "enums.h"
#include "Classess.h"

using namespace GTAIV;

struct un_de
{
	PedBone from;
	PedBone to;
};

extern un_de skeleton_pedbone_data[];



class bone_data
{
	typedef int32_t ped_index;
public:
	bone_data(ped_index pedindex);
	bone_data() :m_pedindex(0), data(nullptr) {};
	bone_data(const bone_data&);
	bone_data(bone_data&&);
	void operator=(bone_data&&);
	void operator=(const bone_data&);
	inline void set_index(ped_index index) { this->m_pedindex = index; }
	inline ped_index get_index() { return this->m_pedindex; }
	inline bone_t* get_data() { return this->data; };
	~bone_data();
private:
	ped_index m_pedindex;
	bone_t* data = nullptr;
};

