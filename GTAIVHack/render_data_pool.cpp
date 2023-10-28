#include "render_data_pool.h"
#include <iostream>
#include <fstream>
extern std::fstream logstream;

bone_data_pool::bone_data_pool()
{
	this->m_cout = 0x200;
	m_object = new render_data[this->m_cout];
	render_data* ptr = m_object;
	for (int i = 0; i < this->m_cout; i++)
	{
		ptr->set_index(i);
		ptr++;
	}
	logstream << "[+] Create bone_data_pool\n";
	logstream.flush();
}
bone_data_pool::~bone_data_pool()
{
	if (this->m_object != nullptr)
	{
		logstream << "[+] ~bone_data_pool\n";
		logstream.flush();
		delete[] m_object;
		m_object = nullptr;
	}
}
render_data* bone_data_pool::read_bone_data_from_index(int index)
{
	if (index < 0 || index + 1 > this->m_cout)
		return &m_object[0];

	return &m_object[index];
}
void bone_data_pool::set_bone_data_from_index(int index, render_data&& data)
{
	if (index < 0 || index + 1 > this->m_cout)
		return;
	m_object[index].set_update_data(std::move(data));
}