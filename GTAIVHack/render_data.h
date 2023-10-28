#pragma once
#include <cstdint>
#include "enums.h"
#include "Classess.h"
#include <memory>

using namespace GTAIV;

struct un_de
{
	PedBone from;
	PedBone to;
};

extern un_de skeleton_pedbone_data[];


struct BoneDeleter {
	inline void operator()(bone_t* arr) const {
		delete[] arr;
	}
};
struct CubeDelete {
	inline void operator()(cube_t* arr)const {
		delete[] arr;
	}
};
class render_data
{
	typedef int32_t ped_index;
public:
	render_data(ped_index pedindex);
	render_data():render_data(0){}
	render_data(render_data&&);
	
	void set_update_data(render_data&&);
	inline void set_index(ped_index index) { this->m_pedindex = index; }
	inline ped_index get_index() { return this->m_pedindex; }
	std::shared_ptr<bone_t> get_data();
	inline std::shared_ptr<cube_t> get_cube_data() { return this->cubedata; }
	inline void set_cube_data_null() { this->cubedata = nullptr; }
	bool update();
	~render_data();
private:
	
	ped_index m_pedindex;
	std::shared_ptr<bone_t> data;
	std::shared_ptr<bone_t> update_data;
	std::shared_ptr<cube_t> cubedata;
	std::shared_ptr<cube_t> update_cubedata;
	bool is_update;
};

