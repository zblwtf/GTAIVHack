#include "bone_data.h"
#include <cstdlib>
#include <string>
un_de skeleton_pedbone_data[] = { {Root,¹ÇÅè},{¹ÇÅè,¼¹Öù},{¼¹Öù,¼¹Öù1},{¼¹Öù1,¼¹Öù2},{¼¹Öù2,¼¹Öù3},{¼¹Öù3,²±×Ó},{²±×Ó,head},{¼¹Öù3,×óËø¹Ç},{×óËø¹Ç,×óÉÏ±Û},{×óÉÏ±Û,×óÇ°±Û},{×óÇ°±Û,×óÊÖ},{¼¹Öù3,ÓÒËø¹Ç},{ÓÒËø¹Ç,ÓÒÉÏ±Û},{ÓÒÉÏ±Û,ÓÒÇ°±Û},{ÓÒÇ°±Û,ÓÒÊÖ},{¹ÇÅè,×ó´óÍÈ},{×ó´óÍÈ,×óÐ¡ÍÈ},{×óÐ¡ÍÈ,×ó½Å} ,{×ó½Å,×ó½ÅÖº},{¹ÇÅè,ÓÒ´óÍÈ},{ÓÒ´óÍÈ,ÓÒÐ¡ÍÈ},{ÓÒÐ¡ÍÈ,ÓÒ½Å} ,{ÓÒ½Å,ÓÒ½ÅÖº} };


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

