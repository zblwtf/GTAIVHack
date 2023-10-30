#include "render_data.h"
#include <memory>
#include <cstdlib>
#include <string>
#include <fstream>
#include <mutex>
extern std::fstream logstream;
un_de skeleton_pedbone_data[] = { {Root,����},{����,����},{����,����1},{����1,����2},{����2,����3},{����3,����},{����,head},{����3,������},{������,���ϱ�},{���ϱ�,��ǰ��},{��ǰ��,����},{����3,������},{������,���ϱ�},{���ϱ�,��ǰ��},{��ǰ��,����},{����,�����},{�����,��С��},{��С��,���} ,{���,���ֺ},{����,�Ҵ���},{�Ҵ���,��С��},{��С��,�ҽ�} ,{�ҽ�,�ҽ�ֺ} };



render_data::render_data(ped_index pedhandle) :m_pedindex(pedhandle), data(nullptr, BoneDeleter{}), is_update(false), update_data(nullptr, BoneDeleter{}), cubedata(nullptr, CubeDelete{}), update_cubedata(nullptr, CubeDelete{})
{
	this->data.reset(new bone_t[skeleton_pedbone_data_size]);
	this->cubedata.reset(new cube_t[cube_data_size]);
	memset(data.get(), 0, sizeof(bone_t) * skeleton_pedbone_data_size);
	memset(cubedata.get(), 0, sizeof(cube_t) * cube_data_size);
}

render_data::render_data(render_data&& rvalue) :m_pedindex(rvalue.m_pedindex), data(nullptr, BoneDeleter{}), is_update(false), update_data(nullptr, BoneDeleter{})
{

	this->data = rvalue.data;
	this->cubedata = rvalue.cubedata;
	rvalue.cubedata = nullptr;
	rvalue.data = nullptr;
}




void render_data::set_update_data(render_data&& rvalue)
{
	//������index ֻ��this->data �ᱻ�ı�
	//this->m_pedindex = rvalue.get_index();
	
	this->update_data = rvalue.data;
	this->update_cubedata = rvalue.cubedata;
	
	this->is_update = true;
		
	

	rvalue.data = nullptr;
	rvalue.cubedata = nullptr;

}
bool render_data::update()
{
	//logstream << "[+]Invoke update()\n";
	bool ret = false;
	do
	{
		bool update_istrue = false;
		std::shared_ptr<bone_t> to_update_ptr = this->update_data;
		std::shared_ptr<cube_t> to_update_cubeptr = this->update_cubedata;

		
		update_istrue = this->is_update;
		


		if (update_istrue == false)
		{
			//logstream << " update_istrue = false\n";
			break;
		}

		if (to_update_ptr.get() == nullptr && to_update_cubeptr.get() == nullptr)
		{
			//logstream << "to_update_ptr = nullptr\n";
			break;

		}

		

		if (to_update_ptr.get() != nullptr)
		{
			this->data = to_update_ptr;
		}
		if (to_update_cubeptr.get() != nullptr)
		{
			this->cubedata = to_update_cubeptr;
		}


		ret = true;
		
		this->is_update = false;
		

		//logstream << " update_bone\n";
		

		//don't change update_data because workshop thread  is writing this var
		//this->update_data = nullptr;

	} while (false);
	//logstream << "[+] Invoke update() Done!\n";
	//logstream.flush();
	return  ret;
	
	

	
	
}

std::shared_ptr<bone_t> render_data::get_data() 
{
	
	return this->data;
};



render_data::~render_data()
{
	if (data.get() != nullptr)
	{
		
		this->data = nullptr;
	}
	if (update_data.get() != nullptr)
	{
		
		this->data = nullptr;

	}
}

